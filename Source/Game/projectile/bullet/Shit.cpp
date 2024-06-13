#include "stdafx.h"
#include "Shit.h"

#include "../../manager/ObjectManager.h"
#include "../shock_wave/BlowUp.h"

Shit::Shit() {
    SetProjectileType(ProjectileType::SHIT);
}

void Shit::Start() {
    Bullet::Start();
}

void Shit::LoadResources() {
    SetImages("Resources/bullet/shit/", 3, RGB(255, 255, 255));
}

void Shit::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void Shit::OnRemove() {
    Bullet::OnRemove();
    BlowUp* blowUp = new BlowUp();
    blowUp->SetPosition(this->position);
    blowUp->SetDamage(5);
    blowUp->AddTag(Tag::MONSTER_ATTACK);
    blowUp->AddTag(Tag::PLAYER_ATTACK);
    ObjectManager::Instance()->AddObject(blowUp);
}
