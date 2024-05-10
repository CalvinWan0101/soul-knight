#include "stdafx.h"
#include "Boar.h"

#include "../../../../weapon/melee_weapon/FakeWeapon.h"

Boar::Boar(double level = 1) : Monster(level) {
}

void Boar::Start() {
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 4;
    this->hp = maxHp;
    this->SetWeapon(new FakeWeapon());
    Monster::Start();
}

void Boar::Update() {
    Monster::Update();
}
