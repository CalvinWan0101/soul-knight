#pragma once
#include "BossSkill.h"

class ZulanSkill2 : public BossSkill
{
public:
    ZulanSkill2(Monster* author);
    bool Update() override;
};
