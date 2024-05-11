#pragma once

class Projectile {
public:
    Projectile();
    void SetDamage(double damage);
    double GetDamage();
protected:
    double damage;
};

