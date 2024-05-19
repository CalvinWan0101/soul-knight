#include "stdafx.h"
#include "Drop.h"

Drop::Drop() : player(nullptr) {
    AddTag(Tag::PLAYER_ALERTABLE);
}

void Drop::Start() {
    GeneralObject::Start();
    SetHitBoxByRatio(1,1);
}

void Drop::Update() {
    GeneralObject::Update();
    if (player) {
        Vec speed = player->GetPosition() - this->position;
        speed.SetLength(10);
        this->speed = speed;
    }
}

void Drop::Collision(GameObject* gameObject) {
}

void Drop::EnterPlayerAlertRange(Player* player) {
    if (!this->player) {
        this->player = player;
    }
}

DropType Drop::GetDropType() {
    return dropType;
}

void Drop::SetDropType(DropType type) {
    this->dropType = type;
}