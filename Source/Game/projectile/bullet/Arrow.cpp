#include "stdafx.h"
#include "Arrow.h"

Arrow::Arrow() {
}

void Arrow::Start() {
    SetImages("Resources/bullet/arrow/", 3, RGB(255, 255, 255));
    Bullet::Start();
}

void Arrow::Update() {
    Bullet::Update();
    SetRotation(&speed);
}