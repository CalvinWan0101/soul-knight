#include "stdafx.h"
#include "RotatableShockWave.h"

void RotatableShockWave::Start() {
    activicated = false;
    RotatableObject::Start();
}

void RotatableShockWave::Update() {
    RotatableObject::Update();
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

void RotatableShockWave::SetAliveTime(double second) {
    this->aliveFrame = static_cast<int>(second * 50);
}


