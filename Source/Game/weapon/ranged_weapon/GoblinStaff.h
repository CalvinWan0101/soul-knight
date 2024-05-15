#pragma once
#include "../RangedWeapon.h"

class GoblinStaff : public RangedWeapon {
public:
    GoblinStaff(Point point);
    GoblinStaff(double damage = 3);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
