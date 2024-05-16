#include "stdafx.h"
#include "Boar.h"

#include "../../../../weapon/melee_weapon/FakeWeapon.h"

Boar::Boar(double level = 1) : Monster(level) {
}

void Boar::Start() {
    Monster::Start();
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 2;

    this->angryKeepFrame = 50;
    this->clamKeepFrame = 150;
    this->angryCounter = 0;
    this->calmCounter = clamKeepFrame;
    this->isAngry = false;
    this->boarDump = new BoarDump();
    this->boarDump->SetVisible(false);
    AddFrontChild(boarDump);
}

void Boar::Update() {
    Monster::Update();
    this->boarDump->SetPosition(position);
    this->boarDump->SetAnimationIndex(static_cast<int>(face));
    if (hp <= 0) {
        DumpState(false);
    }
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
        this->boarDump->SetVisible(true);
    }
    else {
        this->maxSpeed = 2;
        RemoveTag(Tag::MONSTER_ATTACK);
        this->boarDump->SetVisible(false);
    }
}

void Boar::InitializeWeapon() {
    this->SetWeapon(new FakeWeapon());
}



