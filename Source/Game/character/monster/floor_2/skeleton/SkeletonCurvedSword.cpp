#include "stdafx.h"
#include "SkeletonCurvedSword.h"

#include "../../../../weapon/melee_weapon/CurvedSword.h"

SkeletonCurvedSword::SkeletonCurvedSword(double level) : Skeleton(level, true) {
}

void SkeletonCurvedSword::Start() {
    Skeleton::Start();
    SetMonsterType(MonsterType::SKELETON_CURVED_SWORD);
}

void SkeletonCurvedSword::InitializeWeapon() {
    this->SetWeapon(new CurvedSword(4));
}
