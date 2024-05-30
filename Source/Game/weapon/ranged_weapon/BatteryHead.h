#pragma once
#include "../RangedWeapon.h"

class BatteryHead : public RangedWeapon{
public:
    BatteryHead(double damage = 5, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
