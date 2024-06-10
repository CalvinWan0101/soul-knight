#pragma once
#include "BossSkill.h"

class ZulanSkill3 : public BossSkill
{
public:
    ZulanSkill3(Monster* author);
    bool Update() override;
};
