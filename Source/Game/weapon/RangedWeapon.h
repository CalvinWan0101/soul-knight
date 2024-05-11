#pragma once
#include "Weapon.h"
#include "../utils/object/RotatableObject.h"

class RangedWeapon : public Weapon {
public:
    RangedWeapon();
    RangedWeapon(Point point);
    RangedWeapon(double damage);
    void Start() override;
    void Update() override;
    void Attack() override = 0;
};
