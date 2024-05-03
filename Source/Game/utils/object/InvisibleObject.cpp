#include "stdafx.h"
#include "InvisibleObject.h"

void InvisibleObject::Start() {
    GameObject::Start();
}

void InvisibleObject::Update() {
    GameObject::Update();
}

void InvisibleObject::Show(Point screenPositoin) {
    // do nothing
}

void InvisibleObject::SetHitBoxByRatio(double heightRatio, double widthRatio) {
    // do nothing
}

void InvisibleObject::SetCenter() {
    // do nothing
}




