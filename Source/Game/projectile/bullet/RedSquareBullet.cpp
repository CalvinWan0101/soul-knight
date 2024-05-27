#include "stdafx.h"
#include "RedSquareBullet.h"

RedSquareBullet::RedSquareBullet() {
    SetProjectileType(ProjectileType::RED_SQUARE_BULLET);
}

void RedSquareBullet::Start() {
    Bullet::Start();
}

void RedSquareBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void RedSquareBullet::LoadResources() {
    SetImages("Resources/bullet/red_square_bullet/", 3, RGB(255, 255, 255));
}
