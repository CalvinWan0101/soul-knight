#include "stdafx.h"
#include "RedRectangleBullet.h"

RedRectangleBullet::RedRectangleBullet() {
    SetProjectileType(ProjectileType::RED_RECTANGLE_BULLET);
}

void RedRectangleBullet::Start() {
    Bullet::Start();
}

void RedRectangleBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void RedRectangleBullet::LoadResources() {
    SetImages("Resources/bullet/red_rectangle_bullet/", 3, RGB(255, 255, 255));
}