#include "stdafx.h"
#include "BigRedCircleBullet.h"

#include "RedCircleBullet.h"
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
    Bullet::Collision(gameObject);
    if ((gameObject->HasTag(Tag::PLAYER) && this->HasTag(Tag::MONSTER_ATTACK)) ||
        (gameObject->HasTag(Tag::MONSTER) && !gameObject->HasTag(Tag::DEAD) && this->HasTag(Tag::PLAYER_ATTACK)) ||
        gameObject->HasTag(Tag::OBSTACLE)) {
        ProjectilePool* projectilePool = ProjectilePool::Instance();
        ObjectManager* objectManager = ObjectManager::Instance();

        Vec currentRotation = this->rotation;

        for (int i = 0; i < 12; ++i) {
            Bullet* bullet = static_cast<RedCircleBullet*>(projectilePool->Acquire(ProjectileType::RED_CIRCLE_BULLET));
            bullet->SetSpeed(currentRotation, 7);
            bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
            bullet->SetDamage(this->GetDamage());
            UpdateTag(bullet);
            objectManager->AddObject(bullet);
            currentRotation.Rotate(-0.2);
        }
    }
}

void BigRedCircleBullet::UpdateTag(Bullet* bullet) {
    if (HasTag(Tag::PLAYER_ATTACK)) {
        bullet->AddTag(Tag::PLAYER_ATTACK);
        bullet->RemoveTag(Tag::MONSTER_ATTACK);
    }
    else {
        bullet->AddTag(Tag::MONSTER_ATTACK);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
    }
}
