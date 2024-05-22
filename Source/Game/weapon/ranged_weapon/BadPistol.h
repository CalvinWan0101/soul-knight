#pragma once
#include "../RangedWeapon.h"

class BadPistol : public RangedWeapon {
public:
    BadPistol(double damage = 2, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
