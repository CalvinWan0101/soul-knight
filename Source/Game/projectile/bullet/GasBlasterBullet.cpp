#include "stdafx.h"
#include "GasBlasterBullet.h"

GasBlasterBullet::GasBlasterBullet() {
    SetProjectileType(ProjectileType::GAS_BLASTER_BULLET);
}

void GasBlasterBullet::Start() {
    Bullet::Start();
}

void GasBlasterBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void GasBlasterBullet::LoadResources() {
    SetImages("Resources/bullet/gas_blaster_bullet/", 3, RGB(255, 255, 255));
}