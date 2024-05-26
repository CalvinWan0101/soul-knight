#include "stdafx.h"
#include "EliteSkeletonRifle.h"

#include "../../../../weapon/ranged_weapon/Rifle.h"

EliteSkeletonRifle::EliteSkeletonRifle(double level) : EliteSkeleton(level) {
}

void EliteSkeletonRifle::Start() {
    EliteSkeleton::Start();
    SetMonsterType(MonsterType::ELITE_SKELETON_RIFLE);
}

void EliteSkeletonRifle::InitializeWeapon() {
    this->SetWeapon(new Rifle(3));
}
