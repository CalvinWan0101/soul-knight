#include "stdafx.h"
#include "ShockWave.h"

ShockWave::ShockWave() {
    AddTag(Tag::PROJECTILE);
}


void ShockWave::Start() {
    OnceAnimationObject::Start();
    activicated = false;
    SetHitBoxByRatio(0.7, 0.7);
}

void ShockWave::Update() {
    OnceAnimationObject::Update();
    if (activicated && HasTag(Tag::PLAYER_ATTACK)) {
        RemoveTag(Tag::PLAYER_ATTACK);
    }

    if (!activicated) {
        activicated = true;
    }

    if (isAnimationFinished) {
        isAnimationFinished = false;
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}
