#pragma once
#include "../MeleeWeapon.h"

class LongBlade40m : public MeleeWeapon{
public:
    LongBlade40m(double damage = 12, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
