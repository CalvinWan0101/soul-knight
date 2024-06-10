#pragma once
#include "BossSkill.h"

class ZulanSkill4 : public BossSkill
{
public:
    ZulanSkill4(Monster* author);
    bool Update() override;
private:
    int keepFrame;
};
