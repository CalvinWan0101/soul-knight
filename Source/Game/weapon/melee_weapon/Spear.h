#pragma once
#include "../MeleeWeapon.h"

class Spear : public MeleeWeapon {
public:
    Spear();
    Spear(Point point);
    Spear(double damage);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
