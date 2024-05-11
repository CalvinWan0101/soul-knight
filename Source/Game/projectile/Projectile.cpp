#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile(): damage(0) {
}

double Projectile::GetDamage() {
    return damage;
}

void Projectile::SetDamage(double damage) {
    this->damage = damage;
}
