#include "stdafx.h"
#include "RedSplinterBullet.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

RedSplinterBullet::RedSplinterBullet() {
    SetProjectileType(ProjectileType::RED_SPLINTER_BULLET);
}

void RedSplinterBullet::Start() {
    Bullet::Start();
    startPoint = GetPosition();
}

void RedSplinterBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);

    if (startPoint.Distance(GetPosition()) > 30) {
        ProjectilePool* projectilePool = ProjectilePool::Instance();
        ObjectManager* objectManager = ObjectManager::Instance();
        Vec currentRotation = this->rotation;

        currentRotation.Rotate(0.2);

        Bullet* bullet1 = static_cast<RedSplinterBullet*>(projectilePool->Acquire(ProjectileType::RED_CIRCLE_BULLET));
        bullet1->SetSpeed(currentRotation, 7);
        bullet1->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet1->SetDamage(this->GetDamage() - 1);
        UpdateTag(bullet1);
        objectManager->AddObject(bullet1);

        currentRotation.Rotate(-0.2);

        Bullet* bullet2 = static_cast<RedSplinterBullet*>(projectilePool->Acquire(ProjectileType::RED_CIRCLE_BULLET));
        bullet2->SetSpeed(currentRotation, 7);
        bullet2->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet2->SetDamage(this->GetDamage() - 1);
        UpdateTag(bullet2);
        objectManager->AddObject(bullet2);

        currentRotation.Rotate(-0.2);

        Bullet* bullet3 = static_cast<RedSplinterBullet*>(projectilePool->Acquire(ProjectileType::RED_CIRCLE_BULLET));
        bullet3->SetSpeed(currentRotation, 7);
        bullet3->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet3->SetDamage(this->GetDamage() - 1);
        UpdateTag(bullet3);
        objectManager->AddObject(bullet3);
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void RedSplinterBullet::LoadResources() {
    SetImages("Resources/bullet/red_splinter_bullet/", 3, RGB(255, 255, 255));
}

void RedSplinterBullet::UpdateTag(Bullet* bullet) {
    if (HasTag(Tag::PLAYER_ATTACK)) {
        bullet->AddTag(Tag::PLAYER_ATTACK);
        bullet->RemoveTag(Tag::MONSTER_ATTACK);
    }
    else {
        bullet->AddTag(Tag::MONSTER_ATTACK);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
    }
}
