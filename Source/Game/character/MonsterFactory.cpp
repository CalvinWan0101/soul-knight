#include "stdafx.h"
#include "MonsterFactory.h"

#include "monster/floor_1/goblin_giant/GoblinGiant.h"
#include "monster/floor_1/boar/DireBoar.h"
#include "monster/floor_1/boar/NormalBoar.h"
#include "monster/floor_1/elite_goblin_guard/EliteGoblinGuardDart.h"
#include "monster/floor_1/elite_goblin_guard/EliteGoblinGuardHoe.h"
#include "monster/floor_1/elite_goblin_guard/EliteGoblinGuardShotgun.h"
#include "monster/floor_1/goblin_guard/GoblinGuardBow.h"
#include "monster/floor_1/goblin_guard/GoblinGuardPistol.h"
#include "monster/floor_1/goblin_guard/GoblinGuardSpear.h"
#include "monster/floor_1/goblin_shaman/GoblinShaman.h"
#include "monster/floor_2/big_skeleton/BigSkeleton.h"
#include "monster/floor_2/elite_skeleton/EliteSkeletonCurvedSword.h"
#include "monster/floor_2/elite_skeleton/EliteSkeletonRifle.h"
#include "monster/floor_2/elite_skeleton/EliteSkeletonShotgun.h"
#include "monster/floor_2/skeleton/SkeletonBow.h"
#include "monster/floor_2/skeleton/SkeletonCurvedSword.h"
#include "monster/floor_2/skeleton/SkeletonShotgun.h"

Monster* MonsterFactory::Create(MonsterType type, double level) {
    switch (type) {
    // level 1
    case MonsterType::GOBLIN_GIANT:
        return new GoblinGiant(level);

    case MonsterType::GOBLIN_GUARD_SPEAR:
        return new GoblinGuardSpear(level);
    case MonsterType::GOBLIN_GUARD_PISTOL:
        return new GoblinGuardPistol(level);
    case MonsterType::GOBLIN_GUARD_BOW:
        return new GoblinGuardBow(level);

    case MonsterType::ELITE_GOBLIN_GUARD_SHOTGUN:
        return new EliteGoblinGuardShotgun(level);
    case MonsterType::ELITE_GOBLIN_GUARD_DART:
        return new EliteGoblinGuardDart(level);
    case MonsterType::ELITE_GOBLIN_GUARD_HOE:
        return new EliteGoblinGuardHoe(level);

    case MonsterType::GOBLIN_SHAMAN:
        return new GoblinShaman(level);

    case MonsterType::NORMAL_BOAR:
        return new NormalBoar(level);
    case MonsterType::DIRE_BOAR:
        return new DireBoar(level);

    // level 2
    case MonsterType::SKELETON_BOW:
        return new SkeletonBow(level);
    case MonsterType::SKELETON_CURVED_SWORD:
        return new SkeletonCurvedSword(level);
    case MonsterType::SKELETON_SHOTGUN:
        return new SkeletonShotgun(level);
    case MonsterType::ELITE_SKELETON_CURVED_SWORD:
        return new EliteSkeletonCurvedSword(level);
    case MonsterType::ELITE_SKELETON_RIFLE:
        return new EliteSkeletonRifle(level);
    case MonsterType::ELITE_SKELETON_SHOTGUN:
        return new EliteSkeletonShotgun(level);
    case MonsterType::BIG_SKELETON:
        return new BigSkeleton(level);
    default:
        return nullptr;
    }
}
