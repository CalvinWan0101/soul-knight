#pragma once
#include "BossSkill.h"

class FloatingGun;

class ZulanFloatingGunSkill1 : public BossSkill
{
public:
    ZulanFloatingGunSkill1(Monster* author);
    bool Update() override;
private:
    vector<FloatingGun*> floatingGuns;
};
