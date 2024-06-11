#pragma once
#include "../RangedWeapon.h"

class PurpleAxe : public RangedWeapon {
public:
    PurpleAxe(double damage = 4, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
