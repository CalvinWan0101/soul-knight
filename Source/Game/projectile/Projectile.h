#pragma once
#include "ProjectileType.h"

class Projectile {
public:
    Projectile();
    virtual ~Projectile();
    void SetDamage(double damage);
    double GetDamage();
    ProjectileType GetProjectileType();
protected:
    double damage;
    int projectileType;
    void SetProjectileType(ProjectileType type);
};

