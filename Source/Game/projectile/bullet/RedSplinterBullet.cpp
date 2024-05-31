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
        Vec currentRotation = this->rotation;
        rotation.Rotate(0.2);

        for (int i = 0; i < 3; i++) {
            Bullet* bullet = static_cast<RedSplinterBullet*>(ProjectilePool::Instance()->
                Acquire(ProjectileType::RED_CIRCLE_BULLET));
            bullet->SetSpeed(currentRotation, 7);
            bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
            bullet->SetDamage(this->GetDamage() - 1);
            UpdateTag(bullet);
            ObjectManager::Instance()->AddObject(bullet);
            currentRotation.Rotate(-0.2);
        }
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void RedSplinterBullet::LoadResources() {
    SetImages("Resources/bullet/red_splinter_bullet/", 3, RGB(255, 255, 255));
}
