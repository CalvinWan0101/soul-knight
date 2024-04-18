#include "stdafx.h"
#include "hammer.h"

Hammer::Hammer() {
}

void Hammer::Start() {
    cd = 0.5;
    damage = 10;
    SetImages("Resources/weapon/hammer/", 3, RGB(255, 255, 255));
    Knife::Start();
}

void Hammer::Update() {
    Knife::Update();
}

void Hammer::Attack() {
}
