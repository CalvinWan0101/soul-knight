#pragma once
#include "../RangedWeapon.h"

class SplitterCannon : public RangedWeapon {
public:
    SplitterCannon(double damage = 6, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
