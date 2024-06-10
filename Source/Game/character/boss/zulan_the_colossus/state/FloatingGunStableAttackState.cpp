#include "stdafx.h"
#include "FloatingGunStableAttackState.h"
#include "../FloatingGun.h"
#include "../../../Player.h"
#include "../../../../manager/ObjectManager.h"
#include "../../../../utils/Rand.h"

FloatingGunStableAttackState::FloatingGunStableAttackState(FloatingGun* floatingGun) : FloatingGunState(floatingGun)
{
    Initialize();
}

void FloatingGunStableAttackState::Initialize()
{
    keepTimes = 200;
}


void FloatingGunStableAttackState::Update()
{
    floatingGun->SetPosition(floatingGun->GetAuthor()->GetPosition() + floatingGun->GetIdleOffset());
    floatingGun->SetSpeed(0);
    floatingGun->SetRotation(&(ObjectManager::Instance()->GetPlayer()->GetPosition() - floatingGun->GetPosition()));
    keepTimes--;
    if (Rand::Instance()->Get(0,49) == 0)
    {
        floatingGun->AttackFast();
    }
    if (keepTimes == 0)
    {
        Initialize();
        floatingGun->SwitchIdleState();
    }
}

