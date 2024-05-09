#include "stdafx.h"
#include "SpearWave.h"

void SpearWave::Start() {
    SetImages("Resources/bullet/SpearWave/", 3, RGB(255, 255, 255));
    SetHitBoxByRatio(0.5,0.5);
    RotatableShockWave::Start();
}

void SpearWave::Update() {
    RotatableShockWave::Update();
    SetRotation(&speed);
}


