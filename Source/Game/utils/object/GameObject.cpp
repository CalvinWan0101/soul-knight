#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject() : hitBox(position), visible(true), resourcesIsLoaded(false) {
}

GameObject::~GameObject() {
    if (interactiveText) {
        delete interactiveText;
    }
}

void GameObject::Start() {
    if (!resourcesIsLoaded) {
        resourcesIsLoaded = true;
        LoadResources();
    }
    SetCenter();
}

void GameObject::Update() {
    this->position = this->position + this->speed;
}

void GameObject::LoadResources() {
    
}

void GameObject::Show(Point screenPositoin) {
    if (HasTag(Tag::INTERACTABLE)) {
        double screenX = this->position.GetX() - screenPositoin.GetX();
        double screenY = this->position.GetY() - screenPositoin.GetY();
        interactiveText->Show(Point(screenX, screenY));
    }
}

Point GameObject::GetPosition() {
    return position;
}

void GameObject::SetPosition(double x, double y) {
    this->position.SetPoint(x, y);
}

void GameObject::SetPosition(Point point) {
    this->position.SetPoint(point.GetX(), point.GetY());
}

void GameObject::SetX(double x) {
    this->position.SetX(x);
}

void GameObject::SetY(double y) {
    this->position.SetY(y);
}

Vec GameObject::GetSpeed() {
    return speed;
}

void GameObject::SetSpeed(Vec direction, double value) {
    direction.SetLength(value);
    this->speed = direction;
}

void GameObject::SetSpeed(Vec speed) {
    this->speed = speed;
}

void GameObject::SetSpeed(double value) {
    this->speed.SetLength(value);
}

void GameObject::SetSpeedX(double x) {
    this->speed.SetX(x);
}

void GameObject::SetSpeedY(double y) {
    this->speed.SetY(y);
}

void GameObject::SetVisible(bool visible) {
    this->visible = visible;
}

void GameObject::AddTag(Tag tag) {
    tags[static_cast<int>(tag)] = true;
}

void GameObject::RemoveTag(Tag tag) {
    tags[static_cast<int>(tag)] = false;
}

bool GameObject::HasTag(Tag tag) {
    return tags[static_cast<int>(tag)];
}

void GameObject::SetHitBox(double height, double width) {
    hitBox.SetHeight(height);
    hitBox.SetWidth(width);
}

HitBox& GameObject::GetHitBox() {
    return hitBox;
}

void GameObject::Collision(GameObject* gameObject) {
    if (this->HasTag(Tag::INTERACTABLE) && gameObject->HasTag(Tag::PLAYER)) {
        interactiveText->Interactive();
    }
}


void GameObject::SetInteractiveText(string displayText, InteractiveText::Rarity rarity, int verticalOffset) {
    if (interactiveText) {
        delete interactiveText;
    }
    interactiveText = new InteractiveText(displayText, rarity, verticalOffset);
    AddTag(Tag::INTERACTABLE);
}
