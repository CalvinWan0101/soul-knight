#pragma once
#include "../RangedWeapon.h"

class Point;

class Bow : public RangedWeapon {
public:
    Bow(double damage = 6, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
