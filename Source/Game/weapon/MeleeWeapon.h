#pragma once
#include "Weapon.h"

class MeleeWeapon : public Weapon{
public:
    void Start() override;
    void Update() override;
    void Attack() override = 0;
};
