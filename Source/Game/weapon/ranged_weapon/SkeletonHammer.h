#pragma once
#include "../RangedWeapon.h"

class SkeletonHammer : public RangedWeapon {
public:
    SkeletonHammer(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
