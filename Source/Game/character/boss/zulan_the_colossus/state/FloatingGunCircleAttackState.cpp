#include "stdafx.h"
#include "FloatingGunCircleAttackState.h"

#include "../FloatingGun.h"

FloatingGunCircleAttackState::FloatingGunCircleAttackState(FloatingGun* floatingGun) : FloatingGunState(floatingGun)
{
    Initialize();
}

void FloatingGunCircleAttackState::Initialize()
{
    attackTimes = 7;
    attackIntervalCounter = 40;
    rotateDegree = 0;
}


void FloatingGunCircleAttackState::Update()
{
    Vec circlePoint = floatingGun->GetIdleOffset();
    circlePoint.Rotate(rotateDegree);
    floatingGun->SetPosition(floatingGun->GetAuthor()->GetPosition() + circlePoint);
    floatingGun->SetRotation(&circlePoint);
    rotateDegree += 0.05;
    attackIntervalCounter--;

    if (attackIntervalCounter == 0)
    {
        floatingGun->AttackFast();
        attackIntervalCounter = 40;
        attackTimes--;
    }

    if (attackTimes == 0)
    {
        Initialize();
        floatingGun->SwitchStableAttackState();
    }
}

