#pragma once
#include "../RangedWeapon.h"

class Bazooka : public RangedWeapon {
public:
    Bazooka(double damage = 8, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
