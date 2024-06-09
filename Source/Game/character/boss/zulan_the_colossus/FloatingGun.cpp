#include "stdafx.h"
#include "FloatingGun.h"

#include "../../../manager/ObjectManager.h"
#include "../../../pool/ProjectilePool.h"
#include "../../../projectile/bullet/RedRectangleBullet.h"
#include "state/FloatingGunIdleState.h"

FloatingGun::FloatingGun(Monster* author, int id)
{
    this->author = author;
    this->idleState = new FloatingGunIdleState(this);
    this->state = idleState;
    this->idleOffset = Vec(0.0, -30);
    this->idleOffset.Rotate((2 - id) * 1.25);
}

FloatingGun::~FloatingGun()
{
    delete idleState;
}

void FloatingGun::Start()
{
    RotatableObject::Start();
}

void FloatingGun::Update()
{
    RotatableObject::Update();
    state->Update();
}

void FloatingGun::LoadResources()
{
    SetImages("Resources/boss/zulan_the_colossus/floating_gun/",3, RGB(255,255,255));
}

bool FloatingGun::IsIdle()
{
    return idleFlag;
}

void FloatingGun::SetIsIdle()
{
    idleFlag = true;
}

void FloatingGun::SwitchIdleState()
{
    this->state = idleState;
}

void FloatingGun::Attack()
{
    Bullet* bullet;
    Vec currentRotation = this->rotation;
    currentRotation.Rotate(0.4);
    for (int i = 0 ; i < 5 ; i++)
    {
        bullet = static_cast<RedRectangleBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_RECTANGLE_BULLET));
        bullet->SetSpeed(currentRotation, 2);
        bullet->SetPosition(&this->position);
        bullet->SetDamage(3);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        ObjectManager::Instance()->AddObject(bullet);
        currentRotation.Rotate(-0.2);
    }
}

Monster* FloatingGun::GetAuthor()
{
    return author;
}

Vec FloatingGun::GetIdleOffset()
{
    return idleOffset;
}

