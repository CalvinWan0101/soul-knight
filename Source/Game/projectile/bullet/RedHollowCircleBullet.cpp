#include "stdafx.h"
#include "RedHollowCircleBullet.h"

RedHollowCircleBullet::RedHollowCircleBullet() {
    SetProjectileType(ProjectileType::RED_HOLLOW_CIRCLE_BULLET);
}

void RedHollowCircleBullet::Start() {
    Bullet::Start();
    startPoint = GetPosition();
}

void RedHollowCircleBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
    if (startPoint.Distance(GetPosition()) > 50) {
        this->speed = Vec(&rotation, 0.5);
    }
}

void RedHollowCircleBullet::LoadResources() {
    SetImages("Resources/bullet/red_hollow_circle_bullet/", 3, RGB(255, 255, 255));
}