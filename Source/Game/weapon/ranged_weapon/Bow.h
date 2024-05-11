#pragma once
#include "../RangedWeapon.h"

class Point;

class Bow : public RangedWeapon{
public:
    Bow();
    Bow(Point point);
    Bow(double damage);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
