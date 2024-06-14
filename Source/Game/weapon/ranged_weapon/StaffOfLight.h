#pragma once
#include "../RangedWeapon.h"

class StaffOfLight : public RangedWeapon {
public:
    StaffOfLight(double damage = 4, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
