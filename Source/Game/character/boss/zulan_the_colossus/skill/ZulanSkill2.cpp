#include "stdafx.h"
#include "ZulanSkill2.h"

#include "../../../Player.h"
#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/SpiralBullet.h"

ZulanSkill2::ZulanSkill2(Monster* author) : BossSkill(author)
{
}

bool ZulanSkill2::Update()
{
    SpiralBullet* bullet = static_cast<SpiralBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::SPIRAL_BULLET));
    bullet->SetSpeed(ObjectManager::Instance()->GetPlayer()->GetPosition() - author->GetPosition(), 0.4);
    bullet->SetPosition(author->GetPosition());
    bullet->SetDamage(3);
    bullet->RemoveTag(Tag::PLAYER_ATTACK);
    bullet->AddTag(Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet);
    return true;
}
