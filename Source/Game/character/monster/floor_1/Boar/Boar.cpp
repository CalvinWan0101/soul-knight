﻿#include "stdafx.h"
#include "Boar.h"

#include "../../../../weapon/melee_weapon/FakeWeapon.h"

Boar::Boar(double level = 1) : Monster(level) {
}

void Boar::Start() {
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 2;
    this->hp = maxHp;
    this->SetWeapon(new FakeWeapon());
    
    this->angryKeepFrame = 50;
    this->clamKeepFrame = 150;
    this->angryCounter = 0;
    this->calmCounter = clamKeepFrame;
    this->isAngry = false;
    Monster::Start();
}

void Boar::Update() {
    Monster::Update();
}

void Boar::AutoMation() {
    if (isAngry) {
        if (angryCounter <= 0) {
            isAngry = false;
            DumpState(false);
            calmCounter = clamKeepFrame;
        }
        angryCounter--;
    }
    else if (!isAngry) {
        if (calmCounter <= 0) {
            isAngry = true;
            DumpState(true);
            angryCounter = angryKeepFrame;
        }
        calmCounter--;
    }
}

void Boar::DumpState(bool isDump) {
    if (isDump) {
        this->maxSpeed = 6;
        AddTag(Tag::MONSTER_ATTACK);
    }
    else {
        this->maxSpeed = 2;
        RemoveTag(Tag::MONSTER_ATTACK);
    }
}


