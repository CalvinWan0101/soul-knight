#include "stdafx.h"
#include "SkeletonBow.h"

#include "../../../../weapon/ranged_weapon/Bow.h"

SkeletonBow::SkeletonBow(double level) : Skeleton(level) {
}

void SkeletonBow::Start() {
    Skeleton::Start();
    SetMonsterType(MonsterType::SKELETON_BOW);
}

void SkeletonBow::InitializeWeapon() {
    this->SetWeapon(new Bow(5));
}
