#pragma once
#include "../MeleeWeapon.h"

class Spear : public MeleeWeapon {
public:
    Spear(Point point);
    Spear(double damage = 3);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
