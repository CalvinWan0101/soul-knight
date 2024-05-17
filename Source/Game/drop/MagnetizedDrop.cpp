#include "stdafx.h"
#include "MagnetizedDrop.h"

MagnetizedDrop::MagnetizedDrop() : player(nullptr) {
    AddTag(Tag::PLAYER_ALERTABLE);
}

void MagnetizedDrop::Start() {
    GeneralObject::Start();
    SetHitBoxByRatio(1,1);
}

void MagnetizedDrop::Update() {
    GeneralObject::Update();
    if (player) {
        Vec speed = player->GetPosition() - this->position;
        speed.SetLength(10);
        this->speed = speed;
    }
}

void MagnetizedDrop::Collision(GameObject* gameObject) {
}

void MagnetizedDrop::EnterPlayerAlertRange(Player* player) {
    if (!this->player) {
        this->player = player;
    }
}

