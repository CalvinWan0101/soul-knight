#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile(): damage(0) {
}

void Projectile::SetDamage(double damage) {
    this->damage = damage;
}

double Projectile::GetDamage() {
    return damage;
}

bool Projectile::IsProjectileType(ProjectileType type) {
    return static_cast<int>(type) == projectileType;
}

void Projectile::SetProjectileType(ProjectileType type) {
    projectileType = static_cast<int>(type);
}
