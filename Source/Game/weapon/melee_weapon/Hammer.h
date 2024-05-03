#pragma once
#include "../MeleeWeapon.h"

class Hammer : public MeleeWeapon{
public:
    Hammer();
    Hammer(Point point);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
