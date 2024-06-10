#pragma once
#include "BossSkill.h"

class ZulanAngrySkill : public BossSkill
{
public:
    ZulanAngrySkill(Monster* author);
    bool Update() override;
};
