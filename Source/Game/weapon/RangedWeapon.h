#pragma once
#include "weapon.h"
#include "../utils/object/RotatableObject.h"

class RangedWeapon : public Weapon {
public:
    RangedWeapon();
    RangedWeapon(Point point);
    void Start() override;
    void Update() override;
    void Attack() override = 0;
};
