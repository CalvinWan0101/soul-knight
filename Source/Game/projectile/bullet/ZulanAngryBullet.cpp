#include "stdafx.h"
#include "ZulanAngryBullet.h"

#include "RedHollowCircleBullet.h"
#include "../../config.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

ZulanAngryBullet::ZulanAngryBullet()
{
    SetProjectileType(ProjectileType::ZULAN_ANGRY_BULLET);
}

void ZulanAngryBullet::Start()
{
    Bullet::Start();
    splitIntervalCounter = 17;
}

void ZulanAngryBullet::Update()
{
    Bullet::Update();
    splitIntervalCounter--;
    SetRotation(&speed);
    if (splitIntervalCounter == 0)
    {
        splitIntervalCounter = 17;
        RedHollowCircleBullet* bullet;
        Vec angle = this->speed;
        angle.Rotate(-2.6);
        bullet = static_cast<RedHollowCircleBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_HOLLOW_CIRCLE_BULLET));
        bullet->SetPosition(this->position);
        bullet->SetSpeed(angle, 0.5);
        bullet->SetDamage(3);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        ObjectManager::Instance()->AddObject(bullet);

        angle = this->speed;
        angle.Rotate(2.6);
        bullet = static_cast<RedHollowCircleBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_HOLLOW_CIRCLE_BULLET));
        bullet->SetPosition(this->position);
        bullet->SetSpeed(angle, 0.5);
        bullet->SetDamage(3);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        ObjectManager::Instance()->AddObject(bullet);
    }
}

void ZulanAngryBullet::LoadResources()
{
    SetImages("Resources/bullet/red_diamond_bullet/", 3, RGB(255, 255, 255));
}



