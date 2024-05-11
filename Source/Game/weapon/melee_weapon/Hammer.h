#pragma once
#include "../MeleeWeapon.h"

class Hammer : public MeleeWeapon{
public:
    Hammer();
    Hammer(Point point);
    Hammer(double damage);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
