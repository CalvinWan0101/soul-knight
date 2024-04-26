#include "stdafx.h"
#include "shock_wave.h"

void ShockWave::Start() {
    SetHitBoxByRatio(0.7, 0.7);
    OnceAnimationObject::Start();
}

void ShockWave::Update() {
    OnceAnimationObject::Update();
    if (isAnimationFinished) {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

