#include "stdafx.h"
#include "ZulanFloatingGunSkill2.h"

#include "../ZulanTheColossus.h"
#include "../FloatingGun.h"

ZulanFloatingGunSkill2::ZulanFloatingGunSkill2(Monster* author) : BossSkill(author)
{
    floatingGuns = dynamic_cast<ZulanTheColossus*>(author)->GetFloatingGuns();
    for (unsigned int i = 0; i < floatingGuns.size(); i++)
    {
        floatingGuns[i]->SwitchCircleAttackState();
    }
}

bool ZulanFloatingGunSkill2::Update()
{
    for (unsigned int i = 0; i < floatingGuns.size(); i++)
    {
        if (!floatingGuns[i]->IsIdle())
        {
            return false;
        }
    }
    return true;
}