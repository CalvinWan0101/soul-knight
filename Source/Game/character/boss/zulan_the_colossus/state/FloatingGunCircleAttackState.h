#pragma once
#include "FloatingGunState.h"

class FloatingGunCircleAttackState : public FloatingGunState
{
public:
    FloatingGunCircleAttackState(FloatingGun* floatingGun);
    void Initialize();
    void Update() override;
private:
    int attackTimes;
    int attackIntervalCounter;
    double rotateDegree;
};
