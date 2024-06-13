#include "stdafx.h"
#include "SplitterCannonBullet.h"

#include "../../character/Character.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

SplitterCannonBullet::SplitterCannonBullet() {
    SetProjectileType(ProjectileType::SPLITTER_CANNON_BULLET);
}

void SplitterCannonBullet::Start() {
    Bullet::Start();
}

void SplitterCannonBullet::Update() {
    Bullet::Update();
    SetRotation(&speed);
}

void SplitterCannonBullet::LoadResources() {
    SetImages("Resources/bullet/big_yellow_circle_bullet/", 3, RGB(255, 255, 255));
}

void SplitterCannonBullet::Collision(GameObject* gameObject) {
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

void SplitterCannonBullet::SetSplit(bool isSplit) {
    this->isSplit = isSplit;
}

void SplitterCannonBullet::OnRemove() {
    if (isSplit) {
        ProjectilePool* projectilePool = ProjectilePool::Instance();
        ObjectManager* objectManager = ObjectManager::Instance();

        Vec currentRotation = rotation;

        for (int i = 0; i < 12; ++i) {
            Bullet* bullet = static_cast<Bullet*>(projectilePool->Acquire(
                ProjectileType::SMALL_YELLOW_CIRCLE_BULLET));
            bullet->SetSpeed(currentRotation, 4);
            bullet->SetPosition(&(this->position + Vec(&rotation, 7) - this->rotation * 2));
            bullet->SetDamage(2);
            UpdateTag(bullet);
            objectManager->AddObject(bullet);
            currentRotation.Rotate(-(2 * 3.14 / 12));
        }
    }
    isSplit = true;
}
