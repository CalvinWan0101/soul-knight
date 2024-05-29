#include "stdafx.h"
#include "Weapon.h"

#include "../config.h"
#include "../character/Player.h"
#include "../projectile/Bullet.h"

Weapon::Weapon(): cdCounter(0), attackTiming(0), attackRotationOffset(0), attackTranslationOffset(0) {
    AddTag(Tag::PLAYER_WEAPON);
}

void Weapon::Start() {
    RotatableObject::Start();
    SetHitBoxByRatio(1, 1);
}

void Weapon::Update() {
    RotatableObject::Update();
    if (cdCounter > 0) {
        cdCounter--;
        UpdateRotationOffset();
        UpdateTranslationOffset();
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
    Vec translationOffset = this->rotation;
    translationOffset.SetLength(attackTranslationOffset);
    this->showOffset = this->showOffset + translationOffset;
}

void Weapon::Interactive(Player* player) {
    player->ChangeWeapon(Copy());
    AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}

void Weapon::SetAttackAnimation(vector<double> attackRotationOffsets, vector<double> attackTranslationOffsets,
                                double second, double attackTiming) {
    SetFrameCd(second);
    this->attackTiming = attackTiming;
    attackRotationOffsets.emplace_back(0);
    attackTranslationOffsets.emplace_back(0);
    int rotationStep = this->frameCd / static_cast<int>(attackRotationOffsets.size());
    int translationStep = this->frameCd / static_cast<int>(attackTranslationOffsets.size());
    this->attackRotationOffsets = attackRotationOffsets;
    this->attackTranslationOffsets = attackTranslationOffsets;
    this->attackRotationOffsets[0] = attackRotationOffsets[0] / static_cast<double>(rotationStep);
    this->attackTranslationOffsets[0] = attackTranslationOffsets[0] / static_cast<double>(translationStep);
    for (int i = 0; i < static_cast<int>(attackRotationOffsets.size() - 1); i++) {
        this->attackRotationOffsets[i + 1] = (attackRotationOffsets[i + 1] - attackRotationOffsets[i]) / static_cast<
            double>(rotationStep);
    }
    for (int i = 0; i < static_cast<int>(attackTranslationOffsets.size() - 1); i++) {
        this->attackTranslationOffsets[i + 1] = (attackTranslationOffsets[i + 1] - attackTranslationOffsets[i]) /
            static_cast<double>(translationStep);
    }
}

void Weapon::SetFrameCd(double second) {
    this->frameCd = static_cast<int>(second * 50);
}

double Weapon::GetDamage() {
    return damage;
}

void Weapon::SetDamage(double damage) {
    this->damage = damage;
}

int Weapon::GetMpCost() {
    return mpCost;
}

bool Weapon::CanAttack() {
    return cdCounter == 0;
}

void Weapon::UpdateRotationOffset() {
    int step = this->frameCd / static_cast<int>(attackRotationOffsets.size());
    if (frameCd - cdCounter > step * static_cast<int>(attackRotationOffsets.size())) {
        attackRotationOffset = 0;
    }
    else {
        attackRotationOffset += attackRotationOffsets[(frameCd - cdCounter - 1) / step];
    }
}

void Weapon::UpdateTranslationOffset() {
    int step = this->frameCd / static_cast<int>(attackTranslationOffsets.size());
    if (frameCd - cdCounter > step * static_cast<int>(attackTranslationOffsets.size())) {
        attackTranslationOffset = 0;
    }
    else {
        attackTranslationOffset += attackTranslationOffsets[(frameCd - cdCounter - 1) / step];
    }
}

void Weapon::UpdateTag(GameObject* gameObject) {
    if (HasTag(Tag::PLAYER_WEAPON)) {
        gameObject->AddTag(Tag::PLAYER_ATTACK);
        gameObject->RemoveTag(Tag::MONSTER_ATTACK);
    }
    else {
        gameObject->AddTag(Tag::MONSTER_ATTACK);
        gameObject->RemoveTag(Tag::PLAYER_ATTACK);
    }
}
