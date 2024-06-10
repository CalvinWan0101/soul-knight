#include "stdafx.h"
#include "ZulanFloatingGunSkill1.h"

#include "../FloatingGun.h"
#include "../ZulanTheColossus.h"

ZulanFloatingGunSkill1::ZulanFloatingGunSkill1(Monster* author) : BossSkill(author)
{
    floatingGuns = dynamic_cast<ZulanTheColossus*>(author)->GetFloatingGuns();
    for (unsigned int i = 0; i < floatingGuns.size(); i++)
    {
        floatingGuns[i]->SwitchAttackState();
    }
}

bool ZulanFloatingGunSkill1::Update()
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

