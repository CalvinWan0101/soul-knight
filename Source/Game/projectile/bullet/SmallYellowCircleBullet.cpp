#include "stdafx.h"
#include "SmallYellowCircleBullet.h"

SmallYellowCircleBullet::SmallYellowCircleBullet() {
    SetProjectileType(ProjectileType::SMALL_YELLOW_CIRCLE_BULLET);
}

void SmallYellowCircleBullet::Start() {
    Bullet::Start();
}

void SmallYellowCircleBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void SmallYellowCircleBullet::LoadResources() {
    SetImages("Resources/bullet/small_yellow_circle_bullet/", 3, RGB(255, 255, 255));
}