#pragma once
#include "ProjectileType.h"

class Projectile {
public:
    Projectile();
    virtual ~Projectile();
    void SetDamage(double damage);
    double GetDamage();
    ProjectileType GetProjectileType();
    void SetPoison(bool isPoison);
    bool GetPoison();
protected:
    bool isPoison;
    double damage;
    int projectileType;
    void SetProjectileType(ProjectileType type);
};

