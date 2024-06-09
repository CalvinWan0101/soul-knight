#pragma once
#include "FloatingGunState.h"
#include "../../../../utils/Point.h"

class FloatingGunAttackState : public FloatingGunState
{
public:
    FloatingGunAttackState(FloatingGun* floatingGun);
    void Initialize();
    void Update() override;
    void Attack();
    void CheckKeepFrame();
private:
    Point target;
    bool isShooting;
    int waitingCounter;
    int keepFrame;
};
