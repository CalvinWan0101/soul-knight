#include "stdafx.h"
#include "Collectable.h"

Collectable::Collectable() {
    AddTag(Tag::COLLECTABLE);
}

void Collectable::Start() {
    GeneralObject::Start();
    SetHitBoxByRatio(3,3);
}

void Collectable::Update() {
    GeneralObject::Update();
}
