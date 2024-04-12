#include "stdafx.h"
#include "wall.h"

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
