#pragma once
#include "Weapon.h"
#include "../utils/object/RotatableObject.h"

class RangedWeapon : public Weapon {
public:
    void Start() override;
    void Update() override;
    void Attack() override = 0;
};
