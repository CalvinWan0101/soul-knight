#include "stdafx.h"
#include "hammer.h"

Hammer::Hammer() {
}

void Hammer::Start() {
    damage = 10;
    SetImages("Resources/weapon/hammer/", 3, RGB(255, 255, 255));
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, 0.835, 1);
    Knife::Start();
}

void Hammer::Update() {
    Knife::Update();
}

void Hammer::Attack() {
}
