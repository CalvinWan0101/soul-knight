#include "stdafx.h"
#include "invisible_wall.h"

void InvisibleWall::Start() {
    this->AddTag(Tag::WALL);
    InvisibleObject::Start();
}

void InvisibleWall::Update() {
    // do nothing
}

void InvisibleWall::Collision(GameObject* gameObject) {
    // do nothing now
}
