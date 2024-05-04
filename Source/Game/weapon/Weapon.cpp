#include "stdafx.h"
#include "Weapon.h"

#include "../config.h"

Weapon::Weapon() {
    cdCounter = 0;
    attackTiming = 0;
    attackRotationOffset = 0;
    AddTag(Tag::PLAYER_WEAPON);
}

Weapon::Weapon(Point point) {
    this->position = point;
    cdCounter = 0;
    attackTiming = 0;
    attackRotationOffset = 0;
    AddTag(Tag::PLAYER_WEAPON);
}

void Weapon::Start() {
    SetHitBoxByRatio(1,1);
    RotatableObject::Start();
}

void Weapon::Update() {
    RotatableObject::Update();
    if (cdCounter > 0) {
        cdCounter--;
        CalcRotationOffset();
        if (static_cast<double>(frameCd - cdCounter) / static_cast<double>(frameCd) >= attackTiming && isAttack == false) {
            isAttack = true;
            Attack();
        }
    }
}

void Weapon::DefaultAttack() {
    if (cdCounter == 0) {
        cdCounter = frameCd;
        isAttack = false;
        attackFace = (rotation.GetRadian() > PI) ? 1 : -1;
    }
}

void Weapon::Aim(Vec* direction) {
    SetRotation(direction->GetRadian() + attackRotationOffset * attackFace);

}

void Weapon::SetAttackAnimation(vector<double> attackRotationOffsetList, double second, double attackTiming) {
    SetFrameCd(second);
    this->attackTiming = attackTiming;
    attackRotationOffsetList.emplace_back(0);
    int step = this->frameCd / static_cast<int>(attackRotationOffsetList.size());
    this->attackRotationOffsetList = attackRotationOffsetList;
    this->attackRotationOffsetList[0] = attackRotationOffsetList[0] / static_cast<double>(step);
    for (int i = 0 ; i < static_cast<int>(attackRotationOffsetList.size() - 1) ; i++) {
        this->attackRotationOffsetList[i + 1] = (attackRotationOffsetList[i + 1] - attackRotationOffsetList[i]) / static_cast<double>(step);   
    }
}

void Weapon::SetFrameCd(double second) {
    this->frameCd = static_cast<int>(second * 50);
}

int Weapon::GetDamage() {
    return damage;
}

int Weapon::GetMpCost() {
    return mpCost;
}

void Weapon::CalcRotationOffset() {
    int step = this->frameCd / static_cast<int>(attackRotationOffsetList.size());
    if (frameCd - cdCounter > step * static_cast<int>(attackRotationOffsetList.size())) {
        attackRotationOffset = 0;
    }
    else {
        attackRotationOffset += attackRotationOffsetList[(frameCd - cdCounter - 1) / step];
    }
}

