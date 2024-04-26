#include "stdafx.h"
#include "invisible_object.h"

void InvisibleObject::Start() {
    GeneralObject::Start();
}

void InvisibleObject::Update() {
    GeneralObject::Update();
}

void InvisibleObject::Show(Point screenPositoin) {
    // do nothing
}

void InvisibleObject::Collision(GameObject* gameObject) {
    GeneralObject::Collision(gameObject);
}


