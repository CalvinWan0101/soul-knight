#pragma once
#include "../RangedWeapon.h"

class PlungerPlus : public RangedWeapon {
public:
    PlungerPlus(double damage = 6, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
