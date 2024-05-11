#include "stdafx.h"
#include "ProjectilePool.h"

#define PREALLOCATE_BULLET 50
#define PREALLOCATE_SHOCK_WAVE 10

ProjectilePool* ProjectilePool::instance = nullptr;

ProjectilePool* ProjectilePool::Instance() {
    if (instance == nullptr) {
        instance = new ProjectilePool();
    }
    return instance;
}

ProjectilePool::ProjectilePool() {
    // bullet
    for (int i = 0; i < PREALLOCATE_BULLET; i++) {
        arrows.push_back(new Arrow());
    }
    for (int i = 0; i < PREALLOCATE_BULLET; i++) {
        badPistolBullets.push_back(new BadPistolBullet());
    }
    // shock wave
    for (int i = 0; i < PREALLOCATE_SHOCK_WAVE; i++) {
        hammerWaves.push_back(new HammerWave());
    }
    // other
    for (int i = 0; i < PREALLOCATE_SHOCK_WAVE; i++) {
        invisibleShockWaves.push_back(new InvisibleShockWave());
    }
}

ProjectilePool::~ProjectilePool() {
    // bullet
    for (Arrow* arrow : arrows) {
        delete arrow;
    }
    for (BadPistolBullet* bullet : badPistolBullets) {
        delete bullet;
    }
    
    // shock wave
    for (HammerWave* hammerWave : hammerWaves) {
        delete hammerWave;
    }
    
    // other
    for (InvisibleShockWave* invisibleShockWave : invisibleShockWaves) {
        delete invisibleShockWave;
    }
}

// bullet
Arrow* ProjectilePool::AcquireArrow() {
    if (arrows.empty()) {
        arrows.push_back(new Arrow());
    }
    Arrow* arrow = arrows.back();
    arrows.pop_back();
    return arrow;
}

void ProjectilePool::ReleaseArrow(Arrow* arrow) {
    arrow->RemoveTag(Tag::REMOVE_ON_NEXT_FRAME);
    arrows.push_back(arrow);
}

BadPistolBullet* ProjectilePool::AcquireBadPistolBullet() {
    if (badPistolBullets.empty()) {
        badPistolBullets.push_back(new BadPistolBullet());
    }
    BadPistolBullet* bullet = badPistolBullets.back();
    badPistolBullets.pop_back();
    return bullet;
}

void ProjectilePool::ReleaseBadPistolBullet(BadPistolBullet* bullet) {
    bullet->RemoveTag(Tag::REMOVE_ON_NEXT_FRAME);
    badPistolBullets.push_back(bullet);
}

// shock wave
HammerWave* ProjectilePool::AcquireHammerWave() {
    if (hammerWaves.empty()) {
        hammerWaves.push_back(new HammerWave());
    }
    HammerWave* hammerWave = hammerWaves.back();
    hammerWaves.pop_back();
    return hammerWave;
}

void ProjectilePool::ReleaseHammerWave(HammerWave* hammerWave) {
    hammerWave->RemoveTag(Tag::REMOVE_ON_NEXT_FRAME);
    hammerWaves.push_back(hammerWave);
}

// other
InvisibleShockWave* ProjectilePool::AcquireInvisibleShockWave() {
    if (invisibleShockWaves.empty()) {
        invisibleShockWaves.push_back(new InvisibleShockWave());
    }
    InvisibleShockWave* invisibleShockWave = invisibleShockWaves.back();
    invisibleShockWaves.pop_back();
    return invisibleShockWave;
}

void ProjectilePool::ReleaseInvisibleShockWave(InvisibleShockWave* invisibleShockWave) {
    invisibleShockWave->RemoveTag(Tag::REMOVE_ON_NEXT_FRAME);
    invisibleShockWaves.push_back(invisibleShockWave);
}
