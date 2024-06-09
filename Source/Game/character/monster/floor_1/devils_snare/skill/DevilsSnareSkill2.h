#pragma once
#include "DevilsSnareSkill.h"
#include "../../../../../manager/ObjectManager.h"
#include "../../../../../pool/ProjectilePool.h"
#include "../../../../../utils/Point.h"

class DevilsSnareSkill2 : public DevilsSnareSkill {
public:
    DevilsSnareSkill2(Point* position);

private:
    void GenerageBullet() override;
};
