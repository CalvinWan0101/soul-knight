#include "stdafx.h"
#include "arrow.h"
#include "../Library/audio.h"

Arrow::Arrow() {
    game_framework::CAudio::Instance()->Play(0);
}

void Arrow::Start() {
    SetImages("Resources/bullet/bad_bullet/", 3, RGB(255, 255, 255));
    Bullet::Start();
}

void Arrow::Update() {
    Bullet::Update();
    SetRotation(&speed);
}
