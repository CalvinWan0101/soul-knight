#pragma once
#include "../RangedWeapon.h"

class GasBlaster : public RangedWeapon {
public:
    GasBlaster(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
