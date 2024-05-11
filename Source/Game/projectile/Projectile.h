#pragma once
#include "ProjectileType.h"

class Projectile {
public:
    Projectile();
    void SetDamage(double damage);
    double GetDamage();
    bool IsProjectileType(ProjectileType type);
protected:
    double damage;
    int projectileType;
    void SetProjectileType(ProjectileType type);
};

