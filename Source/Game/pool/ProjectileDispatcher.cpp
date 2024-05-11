#include "stdafx.h"
#include "ProjectileDispatcher.h"

#include "ProjectilePool.h"

void ProjectileDispatcher::dispatch(Projectile* projectile) {
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    
    switch (projectile->GetProjectileType()) {
    // bullet
    case ProjectileType::ARROW:
        projectilePool->ReleaseArrow(static_cast<Arrow*>(projectile));
        break;
    case ProjectileType::BAD_PISTOL_BULLET:
        projectilePool->ReleaseBadPistolBullet(static_cast<BadPistolBullet*>(projectile));
        break;
    // shock wave
    case ProjectileType::HAMMER_WAVE:
        projectilePool->ReleaseHammerWave(static_cast<HammerWave*>(projectile));
        break;
    // other
    case ProjectileType::INVISIBLE_SHOCK_WAVE:
        projectilePool->ReleaseInvisibleShockWave(static_cast<InvisibleShockWave*>(projectile));
    default:
        break;
    }
}
