#include "stdafx.h"
#include "RedTriangleBullet.h"

RedTriangleBullet::RedTriangleBullet() {
    SetProjectileType(ProjectileType::RED_TRIANGLE_BULLET);
}

void RedTriangleBullet::Start() {
    Bullet::Start();
}

void RedTriangleBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void RedTriangleBullet::LoadResources() {
    SetImages("Resources/bullet/red_triangle_bullet/", 3, RGB(255, 255, 255));
}
