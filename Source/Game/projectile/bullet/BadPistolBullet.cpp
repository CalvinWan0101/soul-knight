#include "stdafx.h"
#include "BadPistolBullet.h"
#include "../Library/audio.h"

BadPistolBullet::BadPistolBullet() {
    // game_framework::CAudio::Instance()->Play(1);
    SetProjectileType(ProjectileType::BAD_PISTOL_BULLET);
}

void BadPistolBullet::Start() {
    SetImages("Resources/bullet/bad_bullet/", 3, RGB(255, 255, 255));
    Bullet::Start();
}

void BadPistolBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}
