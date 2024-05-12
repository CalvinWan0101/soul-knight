#include "stdafx.h"
#include "InvisibleObject.h"

void InvisibleObject::Start() {
    GameObject::Start();
}

void InvisibleObject::Update() {
    GameObject::Update();
}

void InvisibleObject::LoadResources() {
    // do nothing
}

void InvisibleObject::Show(Point screenPositoin) {
    if (!visible)
        return;
}

void InvisibleObject::SetHitBoxByRatio(double heightRatio, double widthRatio) {
    // do nothing
}

void InvisibleObject::SetCenter() {
    // do nothing
}




