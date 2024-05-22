#pragma once
#include "../MeleeWeapon.h"

class Hoe : public MeleeWeapon {
public:
    Hoe(double damage = 5, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
