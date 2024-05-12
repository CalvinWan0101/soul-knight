#include "stdafx.h"
#include "MonsterFactory.h"

#include "monster/floor_1/goblin_giant/GoblinGiant.h"
#include "monster/floor_1/boar/DireBoar.h"
#include "monster/floor_1/boar/NormalBoar.h"
#include "monster/floor_1/elite_goblin_guard/EliteGoblinGuardHoe.h"
#include "monster/floor_1/elite_goblin_guard/EliteGoblinGuardShotgun.h"
#include "monster/floor_1/goblin_guard/GoblinGuardBow.h"
#include "monster/floor_1/goblin_guard/GoblinGuardPistol.h"
#include "monster/floor_1/goblin_guard/GoblinGuardSpear.h"

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
    case MonsterType::ELITE_GOBLIN_GUARD_HOE:
        return new EliteGoblinGuardHoe(level);

    case MonsterType::NORMAL_BOAR:
        return new NormalBoar(level);
    case MonsterType::DIRE_BOAR:
        return new DireBoar(level);
    default:
        return nullptr;
    }
}
