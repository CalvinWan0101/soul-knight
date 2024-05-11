#pragma once
#include "Weapon.h"

class MeleeWeapon : public Weapon{
public:
    MeleeWeapon();
    MeleeWeapon(Point point);
    MeleeWeapon(double damage);
    void Start() override;
    void Update() override;
    void Attack() override = 0;
};
