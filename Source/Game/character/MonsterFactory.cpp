#include "stdafx.h"
#include "MonsterFactory.h"

#include "monster/floor_1/GoblinGiant.h"

Monster* MonsterFactory::CreateMonster(MonsterType type, double level) {
    switch (type) {
    case MonsterType::GOBLIN_GIANT:
        return new GoblinGiant(level);
    default:
        return nullptr;
    }
}
