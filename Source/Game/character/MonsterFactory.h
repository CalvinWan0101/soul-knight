#pragma once
#include "Monster.h"
#include "MonsterType.h"

class MonsterFactory {
public:
    static Monster* CreateMonster(MonsterType type, double level); 
};
