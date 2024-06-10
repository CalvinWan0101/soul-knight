#pragma once
#include "FloatingGunState.h"

class FloatingGunStableAttackState : public FloatingGunState
{
public:
    FloatingGunStableAttackState(FloatingGun* floatingGun);
    void Initialize();
    void Update() override;
private:
    int keepTimes;
};
