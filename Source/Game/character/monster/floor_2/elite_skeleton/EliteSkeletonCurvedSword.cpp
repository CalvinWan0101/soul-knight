#include "stdafx.h"
#include "EliteSkeletonCurvedSword.h"

#include "../../../../weapon/melee_weapon/CurvedSword.h"

EliteSkeletonCurvedSword::EliteSkeletonCurvedSword(double level) : EliteSkeleton(level) {
}

void EliteSkeletonCurvedSword::Start() {
    EliteSkeleton::Start();
    SetMonsterType(MonsterType::ELITE_SKELETON_CURVED_SWORD);
}

void EliteSkeletonCurvedSword::InitializeWeapon() {
    this->SetWeapon(new CurvedSword(5));
}
