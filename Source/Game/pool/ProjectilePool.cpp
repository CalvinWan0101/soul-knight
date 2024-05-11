#include "stdafx.h"
#include "ProjectilePool.h"

#define PREALLOCATE_PROJECTILES 50

ProjectilePool* ProjectilePool::instance = nullptr;

ProjectilePool* ProjectilePool::Instance() {
    if (instance == nullptr) {
        instance = new ProjectilePool();
    }
    return instance;
}

ProjectilePool::ProjectilePool() {
    for (int i = 0; i < PREALLOCATE_PROJECTILES; i++) {
        badPistolBullets.push_back(new BadPistolBullet());
    }
}

ProjectilePool::~ProjectilePool() {
    for (BadPistolBullet* bullet : badPistolBullets) {
        delete bullet;
    }
}

BadPistolBullet* ProjectilePool::AcquireBadPistolBullet() {
    if (badPistolBullets.empty()) {
        badPistolBullets.push_back(new BadPistolBullet());
    }
    BadPistolBullet* bullet = badPistolBullets.back();
    bullet->RemoveTag(Tag::REMOVE_ON_NEXT_FRAME);
    badPistolBullets.pop_back();
    return bullet;
}

void ProjectilePool::ReleaseBadPistolBullet(BadPistolBullet* bullet) {
    badPistolBullets.push_back(bullet);
}
