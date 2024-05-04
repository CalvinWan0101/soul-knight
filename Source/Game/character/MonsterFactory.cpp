﻿#include "stdafx.h"
#include "MonsterFactory.h"

#include "monster/floor_1/GoblinGiant.h"
#include "monster/floor_1/Boar.h"

Monster* MonsterFactory::CreateMonster(MonsterType type, double level) {
    switch (type) {
    case MonsterType::GOBLIN_GIANT:
        return new GoblinGiant(level);
    case MonsterType::BOAR:
        return new Boar(level);
    default:
        return nullptr;
    }
}
