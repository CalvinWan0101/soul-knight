#include "stdafx.h"
#include "BigRedCircleBullet.h"

#include "RedCircleBullet.h"
#include "../../character/Character.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

BigRedCircleBullet::BigRedCircleBullet() {
    SetProjectileType(ProjectileType::BIG_RED_CIRCLE_BULLET);
}

void BigRedCircleBullet::Start() {
    Bullet::Start();
}

void BigRedCircleBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void BigRedCircleBullet::LoadResources() {
    SetImages("Resources/bullet/big_red_circle_bullet/", 3, RGB(255, 255, 255));
}

void BigRedCircleBullet::Collision(GameObject* gameObject) {
    if ((gameObject->HasTag(Tag::PLAYER) && this->HasTag(Tag::MONSTER_ATTACK)) ||
        (gameObject->HasTag(Tag::MONSTER) && !gameObject->HasTag(Tag::DEAD) && this->HasTag(Tag::PLAYER_ATTACK)) ||
        gameObject->HasTag(Tag::OBSTACLE)) {
        this->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
        if (GetPoison()) {
            if (gameObject->HasTag(Tag::PLAYER)) {
                dynamic_cast<Character*>(gameObject)->Poisoned(1);
            }
            else if (gameObject->HasTag(Tag::MONSTER)) {
                dynamic_cast<Character*>(gameObject)->Poisoned(5);
            }
        }
    }
}

void BigRedCircleBullet::SetSplit(bool isSplit) {
    this->isSplit = isSplit;
}

void BigRedCircleBullet::OnRemove() {
    if (isSplit) {
        ProjectilePool* projectilePool = ProjectilePool::Instance();
        ObjectManager* objectManager = ObjectManager::Instance();

        Vec currentRotation = this->rotation;

        for (int i = 0; i < 12; ++i) {
            Bullet* bullet = static_cast<RedCircleBullet*>(projectilePool->Acquire(ProjectileType::RED_CIRCLE_BULLET));
            bullet->SetSpeed(currentRotation, 4);
            bullet->SetPosition(&(this->position + Vec(&rotation, 7) - this->rotation * 2));
            bullet->SetDamage(2);
            UpdateTag(bullet);
            objectManager->AddObject(bullet);
            currentRotation.Rotate(-0.625);
        }
    }
    isSplit = true;
}
