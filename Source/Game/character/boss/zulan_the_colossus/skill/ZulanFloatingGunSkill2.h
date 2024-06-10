#pragma once
#include "BossSkill.h"

class FloatingGun;

class ZulanFloatingGunSkill2 : public BossSkill
{
public:
    ZulanFloatingGunSkill2(Monster* author);
    bool Update() override;
private:
    vector<FloatingGun*> floatingGuns;
};