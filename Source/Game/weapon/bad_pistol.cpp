#include "stdafx.h"
#include "bad_pistol.h"

#include "../bullet/arrow.h"
#include "../utils/object_manager.h"

BadPistol::BadPistol() {
}

void BadPistol::Start() {
    cd = 0.5;
    SetImages("Resources/weapon/bad_pistol/", 3, RGB(255, 255, 255));
}

void BadPistol::Update() {
    Gun::Update();
}

void BadPistol::Attack() {
    Bullet* bullet = new Arrow();
    bullet->SetSpeed(rotation, 20);
    Vec offset = Vec(&rotation, 6);
    ObjectManager::Instance()->AddPlayerBullets(bullet, offset);
}
