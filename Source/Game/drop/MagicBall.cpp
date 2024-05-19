#include "stdafx.h"
#include "MagicBall.h"

MagicBall::MagicBall() {
    SetDropType(DropType::MAGIC_BALL);
}

void MagicBall::Start() {
    Drop::Start();
}

void MagicBall::Update() {
    Drop::Update();
}

void MagicBall::LoadResources() {
    AddAnimation(
    {"Resources/ui/player_state/mp.bmp"},
    RGB(255,255,255),
    150,
    false
    );
}

void MagicBall::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
        dynamic_cast<Player*>(gameObject)->PickUpMP(rand() % 3 + 1);
    }
}