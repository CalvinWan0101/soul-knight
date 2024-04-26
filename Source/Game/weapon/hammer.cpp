#include "stdafx.h"
#include "hammer.h"

#include "../projectile/shock_wave/shock_wave.h"
#include "../projectile/shock_wave/wave.h"
#include "../utils/object_manager.h"

Hammer::Hammer() {
}

Hammer::Hammer(Point point) : Knife(point) {
}

Weapon* Hammer::Copy() {
    return new Hammer(this->position);
}

void Hammer::Start() {
    damage = 10;
    SetImages("Resources/weapon/hammer/", 3, RGB(255, 255, 255));
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, 0.835, 0.65);
    Knife::Start();
}

void Hammer::Update() {
    Knife::Update();
}

void Hammer::Attack() {
    ShockWave* shockWave = new Wave();
    shockWave->SetPosition(&(this->position + Vec(&rotation, 12) + Vec(0.0, -15)));
    shockWave->SetDamage(10);
    shockWave->AddTag(Tag::PLAYER_ATTACK);
    ObjectManager::Instance()->AddObject(shockWave);
}
