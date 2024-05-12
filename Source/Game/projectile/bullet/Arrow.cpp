#include "stdafx.h"
#include "Arrow.h"

Arrow::Arrow() {
    SetProjectileType(ProjectileType::ARROW);
}

void Arrow::Start() {
    Bullet::Start();
}

void Arrow::LoadResources() {
    SetImages("Resources/bullet/arrow/", 3, RGB(255, 255, 255));
}

void Arrow::Update() {
    Bullet::Update();
    SetRotation(&speed);
}