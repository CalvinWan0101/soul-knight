#pragma once
#include "../MeleeWeapon.h"

class Hoe : public MeleeWeapon {
public:
    Hoe(Point point);
    Hoe(double damage = 5);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
