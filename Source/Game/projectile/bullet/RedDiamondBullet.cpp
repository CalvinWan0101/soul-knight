#include "stdafx.h"
#include "RedDiamondBullet.h"

RedDiamondBullet::RedDiamondBullet() {
    SetProjectileType(ProjectileType::RED_DIAMOND_BULLET);
}

void RedDiamondBullet::Start() {
    Bullet::Start();
}

void RedDiamondBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void RedDiamondBullet::LoadResources() {
    SetImages("Resources/bullet/red_diamond_bullet/", 3, RGB(255, 255, 255));
}
