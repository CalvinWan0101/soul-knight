#include "stdafx.h"
#include "RPG.h"

#include "../../manager/ObjectManager.h"
#include "../shock_wave/BlowUp.h"

RPG::RPG() {
    SetProjectileType(ProjectileType::RPG);
}

void RPG::Start() {
    Bullet::Start();
}

void RPG::LoadResources() {
    SetImages("Resources/bullet/rpg/", 3, RGB(255, 255, 255));
}

void RPG::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void RPG::OnRemove() {
    Bullet::OnRemove();
    BlowUp* blowUp = new BlowUp();
    blowUp->SetPosition(this->position);
    blowUp->SetDamage(5);
    blowUp->AddTag(Tag::MONSTER_ATTACK);
    blowUp->AddTag(Tag::PLAYER_ATTACK);
    ObjectManager::Instance()->AddObject(blowUp);
}
