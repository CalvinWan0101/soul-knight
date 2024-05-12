#include "stdafx.h"
#include "BoarDump.h"

void BoarDump::Start() {
    CharacterAffect::Start();
}

void BoarDump::Update() {
    CharacterAffect::Update();
}

void BoarDump::LoadResources() {
    AddAnimation(
        {
        "Resources/affect/monster/boar_affect/1.bmp",
        "Resources/affect/monster/boar_affect/2.bmp",
        "Resources/affect/monster/boar_affect/3.bmp",
        "Resources/affect/monster/boar_affect/4.bmp"
        }, RGB(255, 255, 255), 100, false);
    AddAnimation(
    {
        "Resources/affect/monster/boar_affect/flip_1.bmp",
        "Resources/affect/monster/boar_affect/flip_2.bmp",
        "Resources/affect/monster/boar_affect/flip_3.bmp",
        "Resources/affect/monster/boar_affect/flip_4.bmp"
    }, RGB(255, 255, 255), 100, false);
}

