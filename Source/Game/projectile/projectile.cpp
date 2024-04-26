#include "stdafx.h"
#include "projectile.h"

Projectile::Projectile() {
    damage = 0;
}


int Projectile::GetDamage() {
    return damage;
}

void Projectile::SetDamage(int damage) {
    this->damage = damage;
}

