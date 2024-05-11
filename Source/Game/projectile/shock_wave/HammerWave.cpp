#include "stdafx.h"
#include "HammerWave.h"

HammerWave::HammerWave() {
    SetProjectileType(ProjectileType::HAMMER_WAVE);
}

void HammerWave::Start() {
    SetAnimation({
        "Resources/affect/weapon/wave/1.bmp",
        "Resources/affect/weapon/wave/2.bmp",
        "Resources/affect/weapon/wave/3.bmp",
        "Resources/affect/weapon/wave/4.bmp",
        "Resources/affect/weapon/wave/5.bmp",
        "Resources/affect/weapon/wave/6.bmp",
        "Resources/affect/weapon/wave/7.bmp",
    }, 100, RGB(255, 255, 255));
    ShockWave::Start();
}

void HammerWave::Update() {
    ShockWave::Update();
}

