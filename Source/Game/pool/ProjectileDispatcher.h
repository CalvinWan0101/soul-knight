#pragma once
#include "../projectile/Projectile.h"

class ProjectileDispatcher {
public:
    static void dispatch(Projectile* projectile);
};
