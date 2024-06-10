#include "stdafx.h"
#include "ZulanSkill1.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/BigRedCircleBullet.h"

ZulanSkill1::ZulanSkill1(Monster* author) : BossSkill(author)
{
}

bool ZulanSkill1::Update()
{
    BigRedCircleBullet* bullet;
    Vec currentRotation(0.0, 1);
    for (int i = 0 ; i < 40 ; i++)
    {
        bullet = static_cast<BigRedCircleBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::BIG_RED_CIRCLE_BULLET));
        bullet->SetSplit(false);
        bullet->SetSpeed(currentRotation, 1);
        bullet->SetPosition(author->GetPosition());
        bullet->SetDamage(3);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        ObjectManager::Instance()->AddObject(bullet);
        currentRotation.Rotate(0.157);
    }
    return true;
}

