#include "stdafx.h"
#include "InvisibleShockWave.h"

InvisibleShockWave::InvisibleShockWave() {
    aliveFrame = 0;
    activicated = false;
    SetProjectileType(ProjectileType::INVISIBLE_SHOCK_WAVE);
}

void InvisibleShockWave::Start() {
    activicated = false;
    InvisibleObject::Start();
}

void InvisibleShockWave::Update() {
    InvisibleObject::Update();
    if (activicated && HasTag(Tag::PLAYER_ATTACK)) {
        RemoveTag(Tag::PLAYER_ATTACK);
    }

    if (!activicated) {
        activicated = true;
    }

    if (aliveFrame <= 0) {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    aliveFrame--;
}

void InvisibleShockWave::SetAliveTime(double second) {
    this->aliveFrame = static_cast<int>(second * 50);
}

void InvisibleShockWave::SetSize(double size) {
    SetHitBox(size, size);
}



