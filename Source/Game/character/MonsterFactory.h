#pragma once
#include "Monster.h"
#include "MonsterType.h"

class MonsterFactory {
public:
    static Monster* Create(MonsterType type, double level); 
};
