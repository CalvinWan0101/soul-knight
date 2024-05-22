#pragma once
#include "../MeleeWeapon.h"

class Hammer : public MeleeWeapon{
public:
    Hammer(double damage = 12, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
