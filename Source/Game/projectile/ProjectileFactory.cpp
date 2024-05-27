#include "stdafx.h"
#include "ProjectileFactory.h"

#include "InvisibleShockWave.h"
#include "ProjectileType.h"
#include "bullet/Arrow.h"
#include "bullet/BadPistolBullet.h"
#include "bullet/GasBlasterBullet.h"
#include "bullet/RedCircleBullet.h"
#include "bullet/RedDiamondBullet.h"
#include "bullet/RedRectangleBullet.h"
#include "bullet/RedSplinterBullet.h"
#include "bullet/RedSquareBullet.h"
#include "shock_wave/HammerWave.h"

Projectile* ProjectileFactory::Create(ProjectileType type) {
    switch (type) {
    // bullet
    case ProjectileType::ARROW:
        return new Arrow();
    case ProjectileType::BAD_PISTOL_BULLET:
        return new BadPistolBullet();
    case ProjectileType::RED_DIAMOND_BULLET:
        return new RedDiamondBullet();
    case ProjectileType::RED_RECTANGLE_BULLET:
        return new RedRectangleBullet();
    case ProjectileType::RED_CIRCLE_BULLET:
        return new RedCircleBullet();
    case ProjectileType::RED_SPLINTER_BULLET:
        return new RedSplinterBullet();
    case ProjectileType::GAS_BLASTER_BULLET:
        return new GasBlasterBullet();
    case ProjectileType::RED_SQUARE_BULLET:
        return new RedSquareBullet();
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
