#pragma once
#include "../MeleeWeapon.h"

class Hammer : public MeleeWeapon{
public:
    Hammer(Point point);
    Hammer(double damage = 5);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
