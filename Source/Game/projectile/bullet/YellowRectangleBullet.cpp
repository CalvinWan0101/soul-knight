#include "stdafx.h"
#include "YellowRectangleBullet.h"

YellowRectangleBullet::YellowRectangleBullet() {
    SetProjectileType(ProjectileType::YELLOW_RECTANGLE_BULLET);
}

void YellowRectangleBullet::Start() {
    Bullet::Start();
}

void YellowRectangleBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void YellowRectangleBullet::LoadResources() {
    SetImages("Resources/bullet/yellow_rectangle_bullet/", 3, RGB(255, 255, 255));
}
