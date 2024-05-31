#include "stdafx.h"
#include "BlowUp.h"

BlowUp::BlowUp() {
    SetProjectileType(ProjectileType::BLOW_UP);
}

void BlowUp::Start() {
    ShockWave::Start();
}

void BlowUp::Update() {
    ShockWave::Update();
}


void BlowUp::LoadResources() {
    SetAnimation({"Resources/affect/weapon/blow-up/1.bmp",
    "Resources/affect/weapon/blow-up/2.bmp",
    "Resources/affect/weapon/blow-up/3.bmp",
    "Resources/affect/weapon/blow-up/4.bmp"},
    150, RGB(255,255,255));
}