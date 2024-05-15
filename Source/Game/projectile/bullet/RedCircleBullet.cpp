#include "stdafx.h"
#include "RedCircleBullet.h"

RedCircleBullet::RedCircleBullet() {
    SetProjectileType(ProjectileType::RED_CIRCLE_BULLET);
}

void RedCircleBullet::Start() {
    Bullet::Start();
}

void RedCircleBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void RedCircleBullet::LoadResources() {
    SetImages("Resources/bullet/red_circle_bullet/", 3, RGB(255, 255, 255));
}
