#include "stdafx.h"
#include "ZulanAngrySkill.h"

#include "../../../Player.h"
#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/ZulanAngryBullet.h"

ZulanAngrySkill::ZulanAngrySkill(Monster* author) : BossSkill(author)
{
}

bool ZulanAngrySkill::Update()
{
    ZulanAngryBullet* bullet;
    Vec currentRotation = ObjectManager::Instance()->GetPlayer()->GetPosition() - author->GetPosition();
    currentRotation.Rotate(-2.18);
    for (int i = 0 ; i < 13 ; i++)
    {
        bullet = static_cast<ZulanAngryBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::ZULAN_ANGRY_BULLET));
        bullet->SetSpeed(currentRotation, 1);
        bullet->SetPosition(author->GetPosition());
        bullet->SetDamage(3);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        ObjectManager::Instance()->AddObject(bullet);
        currentRotation.Rotate(0.335);
    }
    return true;
}
