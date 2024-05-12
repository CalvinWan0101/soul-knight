#pragma once
#include "../RangedWeapon.h"

class BadPistol : public RangedWeapon {
public:
    BadPistol(Point point);
    BadPistol(double damage = 2);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
