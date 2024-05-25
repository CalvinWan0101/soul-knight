#include "stdafx.h"
#include "SkeletonRifle.h"

#include "../../../../weapon/ranged_weapon/Rifle.h"

SkeletonRifle::SkeletonRifle(double level) : Skeleton(level) {
}

void SkeletonRifle::Start() {
    Skeleton::Start();
    SetMonsterType(MonsterType::SKELETON_RIFLE);
}

void SkeletonRifle::InitializeWeapon() {
    this->SetWeapon(new Rifle(3));
}
