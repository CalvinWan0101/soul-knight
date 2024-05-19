#include "stdafx.h"
#include "GeneralObject.h"

#include <algorithm>


GeneralObject::GeneralObject(): cMovingBitmaps({}), index(0), frontGameObjects({}), backGameObjects({}) {
}

GeneralObject::~GeneralObject() {
    for (auto gameObject : frontGameObjects) {
        delete gameObject;
    }
    for (auto gameObject : backGameObjects) {
        delete gameObject;
    }
}

void GeneralObject::Start() {
    GameObject::Start();
}

void GeneralObject::Update() {
    GameObject::Update();
    for (auto gameObject : backGameObjects) {
        gameObject->Update();
    }
    for (auto gameObject : frontGameObjects) {
        gameObject->Update();
    }
}

void GeneralObject::Show(Point screenPositoin) {
    if (!visible)
        return;
    GameObject::Show(screenPositoin);
    double screenX = this->position.GetX() - screenPositoin.GetX();
    double screenY = this->position.GetY() - screenPositoin.GetY();
    for (auto gameObject : backGameObjects) {
        gameObject->Show(screenPositoin);
    }
    cMovingBitmaps[index].SetTopLeft(static_cast<int>(screenX - centerOffset.GetX()),
                                     static_cast<int>(screenY - centerOffset.GetY()));
    cMovingBitmaps[index].ShowBitmap();
    for (auto gameObject : frontGameObjects) {
        gameObject->Show(screenPositoin);
    }
}

void GeneralObject::OnRemove() {
}

void GeneralObject::SetHitBoxByRatio(double heightRatio, double widthRatio) {
    hitBox.SetHeight(static_cast<double>(cMovingBitmaps[0].GetHeight()) * heightRatio);
    hitBox.SetWidth(static_cast<double>(cMovingBitmaps[0].GetWidth()) * widthRatio);
}

void GeneralObject::AddAnimation(vector<string> filepaths, COLORREF color, int delay, bool once) {
    game_framework::CMovingBitmap cMovingBitmap = game_framework::CMovingBitmap();
    cMovingBitmap.LoadBitmapByString(filepaths, color);
    cMovingBitmap.SetAnimation(delay, once);
    cMovingBitmaps.emplace_back(cMovingBitmap);
}

void GeneralObject::AddFrontChild(GameObject* gameObject) {
    gameObject->Start();
    frontGameObjects.emplace_back(gameObject);
}

void GeneralObject::AddBackChild(GameObject* gameObject) {
    gameObject->Start();
    backGameObjects.emplace_back(gameObject);
}

void GeneralObject::RemoveFrontChile(GameObject* frontChild) {
    size_t frontObjects = frontGameObjects.size();
    frontGameObjects.erase(std::remove_if(frontGameObjects.begin(), frontGameObjects.end(),
                                          [frontChild](const GameObject* obj) {
                                              return frontChild == obj;
                                          }), frontGameObjects.end());
    if (frontObjects <= frontGameObjects.size()) {
        throw exception("GameObject Not Found.");
    }
}

void GeneralObject::RemoveBackChild(GameObject* backChild) {
    size_t backObjects = backGameObjects.size();
    backGameObjects.erase(std::remove_if(backGameObjects.begin(), backGameObjects.end(),
                                         [backChild](const GameObject* obj) {
                                             return backChild == obj;
                                         }), backGameObjects.end());
    if (backObjects <= backGameObjects.size()) {
        throw exception("GameObject Not Found.");
    }
}

void GeneralObject::SetCenter() {
    if (!this->cMovingBitmaps.empty()) {
        this->centerOffset.SetVec(cMovingBitmaps[0].GetWidth() / 2, cMovingBitmaps[0].GetHeight() / 2);
    }
}
