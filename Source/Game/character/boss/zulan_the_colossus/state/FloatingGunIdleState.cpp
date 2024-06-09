#include "stdafx.h"
#include "FloatingGunIdleState.h"

#include "../FloatingGun.h"
#include "../../../Player.h"
#include "../../../../manager/ObjectManager.h"
#include "../../../../utils/Rand.h"

FloatingGunIdleState::FloatingGunIdleState(FloatingGun* floatingGun) : FloatingGunState(floatingGun)
{
}

void FloatingGunIdleState::Update()
{
    if ((floatingGun->GetPosition() - floatingGun->GetAuthor()->GetPosition() - floatingGun->GetIdleOffset()).GetLength() < 6)
    {
        floatingGun->SetPosition(floatingGun->GetAuthor()->GetPosition() + floatingGun->GetIdleOffset());
        floatingGun->SetSpeed(0);
        if (!floatingGun->IsIdle())
        {
            floatingGun->SetIsIdle();
        }
    }
    else
    {
        floatingGun->SetSpeed(floatingGun->GetAuthor()->GetPosition() + floatingGun->GetIdleOffset() - floatingGun->GetPosition(), 3);
    }
}

