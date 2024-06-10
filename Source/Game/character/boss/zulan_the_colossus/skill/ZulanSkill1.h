#pragma once
#include "BossSkill.h"

class ZulanSkill1 : public BossSkill
{
public:
    ZulanSkill1(Monster* author);
    bool Update() override;
};
