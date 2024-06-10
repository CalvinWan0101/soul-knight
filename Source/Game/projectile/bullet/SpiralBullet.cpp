#include "stdafx.h"
#include "SpiralBullet.h"

#include "RedCircleBullet.h"
#include "../../config.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

SpiralBullet::SpiralBullet()
{
    SetProjectileType(ProjectileType::SPIRAL_BULLET);
}

void SpiralBullet::Start()
{
    Bullet::Start();
    splitIntervalCounter = 10;
    splitAngle = Vec(0.0,1.5);
}

void SpiralBullet::Update()
{
    Bullet::Update();
    splitIntervalCounter--;
    SetRotation(&speed);
    if (splitIntervalCounter == 0)
    {
        splitIntervalCounter = 10;
        splitAngle.Rotate(0.2);
        RedCircleBullet* bullet;
        for (int i = 0 ; i < 4 ; i++)
        {
            Vec angle = splitAngle;
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
}


void SpiralBullet::LoadResources()
{
    SetImages("Resources/bullet/big_red_circle_bullet/", 3, RGB(255, 255, 255));
}
