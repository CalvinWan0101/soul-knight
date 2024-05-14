#include "stdafx.h"
#include "Door.h"


void Door::Start() {
    GeneralObject::Start();
    SetHitBoxByRatio(1, 1);
}

void Door::Update() {
    GeneralObject::Update();
}
