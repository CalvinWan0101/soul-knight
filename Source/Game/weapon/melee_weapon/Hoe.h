#pragma once
#include "../MeleeWeapon.h"

class Hoe : public MeleeWeapon {
public:
    Hoe();
    Hoe(Point point);
    Hoe(double damage);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
