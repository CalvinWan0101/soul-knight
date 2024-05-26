#include "stdafx.h"
#include "EliteSkeletonShotgun.h"

#include "../../../../weapon/ranged_weapon/Shotgun.h"

EliteSkeletonShotgun::EliteSkeletonShotgun(double level) : EliteSkeleton(level) {
}

void EliteSkeletonShotgun::Start() {
    EliteSkeleton::Start();
    SetMonsterType(MonsterType::ELITE_SKELETON_SHOTGUN);
}

void EliteSkeletonShotgun::InitializeWeapon() {
    this->SetWeapon(new Shotgun(3));
}
