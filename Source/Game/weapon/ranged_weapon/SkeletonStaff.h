#pragma once
#include "../RangedWeapon.h"

class SkeletonStaff : public RangedWeapon {
public:
    SkeletonStaff(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
