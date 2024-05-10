#include "stdafx.h"
#include "MonsterFactory.h"

#include "monster/floor_1/GoblinGiant.h"
#include "monster/floor_1/Boar.h"
#include "monster/floor_1/goblin_guard/GoblinGuardGun.h"
#include "monster/floor_1/goblin_guard/GoblinGuardSpear.h"

Monster* MonsterFactory::CreateMonster(MonsterType type, double level) {
    switch (type) {
    case MonsterType::GOBLIN_GIANT:
        return new GoblinGiant(level);
    case MonsterType::GOBLIN_GUARD_SPEAR:
        return new GoblinGuardSpear(level);
    case MonsterType::GOBLIN_GUARD_GUN:
        return new GoblinGuardGun(level);
    case MonsterType::BOAR:
        return new Boar(level);
    default:
        return nullptr;
    }
}
