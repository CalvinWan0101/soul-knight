#include "stdafx.h"
#include "RedConicalBullet.h"

#include "RedHollowCircleBullet.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

RedConicalBullet::RedConicalBullet() {
    SetProjectileType(ProjectileType::RED_CONICAL_BULLET);
}

void RedConicalBullet::Start() {
    Bullet::Start();
    startPoint = GetPosition();
}

void RedConicalBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
    if (startPoint.Distance(GetPosition()) > 20) {
        Vec currentRotation = this->rotation;
        currentRotation.Rotate(1.57);

        for (int i = 0; i < 2; i++) {
            Bullet* bullet = static_cast<RedHollowCircleBullet*>(ProjectilePool::Instance()->
                Acquire(ProjectileType::RED_HOLLOW_CIRCLE_BULLET));
            bullet->SetSpeed(currentRotation, 7);
            bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
            bullet->SetDamage(this->GetDamage() - 1);
            UpdateTag(bullet);
            ObjectManager::Instance()->AddObject(bullet);
            currentRotation.Rotate(-3.14);
        }
        startPoint = GetPosition();
    }
}

void RedConicalBullet::LoadResources() {
    SetImages("Resources/bullet/red_conical_bullet/", 3, RGB(255, 255, 255));
}
