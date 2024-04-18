#include "stdafx.h"
#include "bad_pistol.h"

#include "../bullet/arrow.h"
#include "../utils/object_manager.h"

BadPistol::BadPistol() {
}

void BadPistol::Start() {
    cd = 0.01;
    damage = 3;
    SetImages("Resources/weapon/bad_pistol/", 3, RGB(255, 255, 255));
    Gun::Start();
}

void BadPistol::Update() {
    Gun::Update();
}

void BadPistol::Attack() {
    Bullet* bullet = new Arrow();
    bullet->SetSpeed(rotation, 1);
    bullet->SetPoint(&(this->point + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->AddTag(Tag::PLAYER_BULLET);
    ObjectManager::Instance()->AddObject(bullet);
}
