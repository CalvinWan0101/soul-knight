#pragma once
#include "../../../Monster.h"

class BossSkill
{
public:
    BossSkill(Monster* author);
    virtual ~BossSkill() = default;
    virtual bool Update() = 0;
protected:
    Monster* author;
};
