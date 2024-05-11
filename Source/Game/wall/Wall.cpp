#include "stdafx.h"
#include "Wall.h"
#include <cmath>

Wall::Wall(Point point1, Point point2) {
    this->position.SetX((point1.GetX() + point2.GetX()) / 2);
    this->position.SetY((point1.GetY() + point2.GetY()) / 2);
    this->hitBox.SetWidth(abs(point1.GetX() - point2.GetX()));
    this->hitBox.SetHeight(abs(point1.GetY() - point2.GetY()));
}

Wall::Wall() {
}


void Wall::Start() {
    this->AddTag(Tag::OBSTACLE);
    InvisibleObject::Start();
}

void Wall::Update() {
    // do nothing
}

void Wall::Collision(GameObject* gameObject) {
    // do nothing now
}
