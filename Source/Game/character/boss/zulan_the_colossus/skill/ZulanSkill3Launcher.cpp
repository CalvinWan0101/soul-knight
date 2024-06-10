#include "stdafx.h"
#include "ZulanSkill3Launcher.h"

#include "../../../../config.h"
#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/RedCircleBullet.h"
#include "../../../../utils/Rand.h"

ZulanSkill3Launcher::ZulanSkill3Launcher(Point point)
{
    aliveFrame = 300;
    while (launchAngle.GetLength() == 0)
    {
        launchAngle = Vec(Rand::Instance()->Get(-10, 10),Rand::Instance()->Get(-10, 10));
    }
    launchAngle.SetLength(2);
    splitIntervalCounter = 10;
    position = point;
}

void ZulanSkill3Launcher::Update()
{
    InvisibleObject::Update();
    if (splitIntervalCounter == 0)
    {
        splitIntervalCounter = 10;
        RedCircleBullet* bullet;
        for (int i = 0 ; i < 4 ; i++)
        {
            Vec angle = launchAngle;
            angle.Rotate(PI / 2 * i);
            bullet = static_cast<RedCircleBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_CIRCLE_BULLET));
            bullet->SetPosition(this->position);
            bullet->SetSpeed(angle);
            bullet->SetDamage(3);
            bullet->RemoveTag(Tag::PLAYER_ATTACK);
            bullet->AddTag(Tag::MONSTER_ATTACK);
            ObjectManager::Instance()->AddObject(bullet);
        }
    }
    
    aliveFrame--;
    if (aliveFrame == 0)
    {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    splitIntervalCounter--;
}
