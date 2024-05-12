#pragma once
#include "../RangedWeapon.h"

class Point;

class Bow : public RangedWeapon{
public:
    Bow(Point point);
    Bow(double damage = 4);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
