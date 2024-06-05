#pragma once
#include "../MeleeWeapon.h"

class PurpleAxe : public MeleeWeapon {
public:
    PurpleAxe(double damage = 6, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
