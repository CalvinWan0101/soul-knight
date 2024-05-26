#include "stdafx.h"
#include "SkeletonShotgun.h"

#include "../../../../weapon/ranged_weapon/Shotgun.h"

SkeletonShotgun::SkeletonShotgun(double level) : Skeleton(level) {
}

void SkeletonShotgun::Start() {
    Skeleton::Start();
    SetMonsterType(MonsterType::SKELETON_SHOTGUN);
}

void SkeletonShotgun::InitializeWeapon() {
    this->SetWeapon(new Shotgun(3));
}
