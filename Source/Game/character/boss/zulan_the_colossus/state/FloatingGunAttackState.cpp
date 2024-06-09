#include "stdafx.h"
#include "FloatingGunAttackState.h"

#include "../FloatingGun.h"
#include "../../../Player.h"
#include "../../../../manager/ObjectManager.h"
#include "../../../../utils/Rand.h"

FloatingGunAttackState::FloatingGunAttackState(FloatingGun* floatingGun) : FloatingGunState(floatingGun)
{
    Initialize();
}

void FloatingGunAttackState::Initialize()
{
    isShooting = true;
    waitingCounter = 50;
    keepFrame = 500;
}


void FloatingGunAttackState::Update()
{
    keepFrame--;
    if (isShooting)
    {
        isShooting = false;
        target = ObjectManager::Instance()->GetPlayer()->GetPosition() + Vec(Rand::Instance()->Get(-100, 100),Rand::Instance()->Get(-100, 100));
        floatingGun->SetSpeed(target - floatingGun->GetPosition(), floatingGun->GetMaxSpeed());
    }
    else
    {
        floatingGun->SetRotation(&(ObjectManager::Instance()->GetPlayer()->GetPosition() - floatingGun->GetPosition()));
        if (floatingGun->GetPosition().Distance(target) < 4)
        {
            Attack();
        }
    }
}

void FloatingGunAttackState::Attack()
{
    waitingCounter--;
    floatingGun->SetSpeed(0);
    if (waitingCounter == 0)
    {
        CheckKeepFrame();
        waitingCounter = Rand::Instance()->Get(25, 75);
        floatingGun->Attack();
        isShooting = true;
    }
}


void FloatingGunAttackState::CheckKeepFrame()
{
    if (keepFrame <= 0)
    {
        Initialize();
        floatingGun->SwitchIdleState();
    }
}

