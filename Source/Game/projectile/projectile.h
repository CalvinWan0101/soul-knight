#pragma once

class Projectile {
public:
    Projectile();
    void SetDamage(int damage);
    int GetDamage();
protected:
    int damage;
};

