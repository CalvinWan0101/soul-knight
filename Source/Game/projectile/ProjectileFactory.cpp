#include "stdafx.h"
#include "ProjectileFactory.h"

#include "InvisibleShockWave.h"
#include "ProjectileType.h"
#include "bullet/Arrow.h"
#include "bullet/BadPistolBullet.h"
#include "shock_wave/HammerWave.h"

Projectile* ProjectileFactory::Create(ProjectileType type) {
    switch (type) {
    // bullet
    case ProjectileType::ARROW:
        return new Arrow();
    case ProjectileType::BAD_PISTOL_BULLET:
        return new BadPistolBullet();
    // shock wave
    case ProjectileType::HAMMER_WAVE:
        return new HammerWave();
    // other
    case ProjectileType::INVISIBLE_SHOCK_WAVE:
        return new InvisibleShockWave();
    default:
        return nullptr;
    }
}
