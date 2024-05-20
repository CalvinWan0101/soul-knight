#include "stdafx.h"
#include "DamageText.h"

#include "../utils/draw/Draw.h"

DamageText::DamageText() : damage(0), maxAliveTime(30) {
    aliveTime = maxAliveTime;
}

void DamageText::Start() {
    InvisibleObject::Start();
}

void DamageText::Update() {
    InvisibleObject::Update();
    aliveTime--;
    if (aliveTime == 0) {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void DamageText::Show(Point screenPositoin) {
    InvisibleObject::Show(screenPositoin);
    double screenX = this->position.GetX() - screenPositoin.GetX();
    double screenY = this->position.GetY() - screenPositoin.GetY();
    game_framework::Draw::Instance()->Text(Point(screenX, screenY), 12, RGB(255,0,0), std::to_string(static_cast<int>(damage)));
}

bool DamageText::IsAlive() {
    return aliveTime > maxAliveTime / 2;
}

void DamageText::AddDamage(double damage) {
    this->damage += damage;
    aliveTime = maxAliveTime;
}
