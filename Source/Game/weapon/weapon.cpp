#include "stdafx.h"
#include "weapon.h"

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
        if (static_cast<double>(cd - cdCounter) / static_cast<double>(cd) >= attackTiming && isAttack == false) {
            isAttack = true;
            Attack();
        }
    }
}

void Weapon::DefaultAttack() {
    if (cdCounter == 0) {
        cdCounter = cd;
        isAttack = false;
        attackFace = (rotation.GetRadian() > PI) ? 1 : -1;
    }
}

void Weapon::Aim(Vec* direction) {
    SetRotation(direction->GetRadian() + attackRotationOffset * attackFace);

}

void Weapon::SetAttackAnimation(vector<double> attackRotationOffsetList, double cd, double attackTiming) {
    SetCd(cd);
    this->attackTiming = attackTiming;
    attackRotationOffsetList.emplace_back(0);
    int step = this->cd / static_cast<int>(attackRotationOffsetList.size());
    this->attackRotationOffsetList = attackRotationOffsetList;
    this->attackRotationOffsetList[0] = attackRotationOffsetList[0] / static_cast<double>(step);
    for (int i = 0 ; i < static_cast<int>(attackRotationOffsetList.size() - 1) ; i++) {
        this->attackRotationOffsetList[i + 1] = (attackRotationOffsetList[i + 1] - attackRotationOffsetList[i]) / static_cast<double>(step);   
    }
}

// Set cd by second
void Weapon::SetCd(double cd) {
    this->cd = static_cast<int>(cd * 50);
}

double Weapon::GetCd() {
    return static_cast<double>(cd) / 50;
}

int Weapon::GetDamage() {
    return damage;
}

int Weapon::GetMpCost() {
    return mpCost;
}

void Weapon::CalcRotationOffset() {
    int step = this->cd / static_cast<int>(attackRotationOffsetList.size());
    if (cd - cdCounter > step * static_cast<int>(attackRotationOffsetList.size())) {
        attackRotationOffset = 0;
    }
    else {
        attackRotationOffset += attackRotationOffsetList[(cd - cdCounter - 1) / step];
    }
}

