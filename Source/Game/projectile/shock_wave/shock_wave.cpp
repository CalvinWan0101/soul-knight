#include "stdafx.h"
#include "shock_wave.h"

void ShockWave::Start() {
    activicated = false;
    SetHitBoxByRatio(0.7, 0.7);
    OnceAnimationObject::Start();
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
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

