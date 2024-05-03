#pragma once
#include "RangedWeapon.h"

class BadPistol : public RangedWeapon {
public:
    BadPistol();
    BadPistol(Point point);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
