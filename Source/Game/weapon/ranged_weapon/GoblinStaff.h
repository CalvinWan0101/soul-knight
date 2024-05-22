#pragma once
#include "../RangedWeapon.h"

class GoblinStaff : public RangedWeapon {
public:
    GoblinStaff(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
