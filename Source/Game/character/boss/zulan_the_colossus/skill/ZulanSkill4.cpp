#include "stdafx.h"
#include "ZulanSkill4.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/RedRectangleBullet.h"
#include "../../../../projectile/bullet/RedSplinterBullet.h"
#include "../../../../projectile/bullet/RedSquareBullet.h"
#include "../../../../utils/Rand.h"

ZulanSkill4::ZulanSkill4(Monster* author) : BossSkill(author)
{
    keepFrame = 250;
}

bool ZulanSkill4::Update()
{
    keepFrame--;
    if (Rand::Instance()->Get(0,1) == 0)
    {
        Vec bulletSpeed;
        while (bulletSpeed.GetLength() == 0)
        {
            bulletSpeed.SetX(Rand::Instance()->Get(-100,100));
            bulletSpeed.SetY(Rand::Instance()->Get(-100,100));
        }
        RedSquareBullet* bullet = static_cast<RedSquareBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_SQUARE_BULLET));
        bullet->SetSpeed(bulletSpeed, 2);
        bullet->SetPosition(author->GetPosition());
        bullet->SetDamage(3);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        ObjectManager::Instance()->AddObject(bullet);
    }
    if (keepFrame == 0)
    {
        return true;
    }
    return false;
}
