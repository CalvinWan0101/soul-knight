#pragma once
#include "../projectile/bullet/BadPistolBullet.h"

class ProjectilePool {
public:
    static ProjectilePool* Instance();
    ProjectilePool();
    ~ProjectilePool();
    BadPistolBullet* AcquireBadPistolBullet();
    void ReleaseBadPistolBullet(BadPistolBullet* bullet);

private:
    static ProjectilePool* instance;
    std::vector<BadPistolBullet*> badPistolBullets;
};
