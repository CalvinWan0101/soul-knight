#include "stdafx.h"
#include "GreenRectangleBullet.h"

GreenRectangleBullet::GreenRectangleBullet() {
    SetProjectileType(ProjectileType::GREEN_RECTANGLE_BULLET);
}

void GreenRectangleBullet::Start() {
    Bullet::Start();
}

void GreenRectangleBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void GreenRectangleBullet::LoadResources() {
    SetImages("Resources/bullet/green_rectangle_bullet/", 3, RGB(255, 255, 255));
}
