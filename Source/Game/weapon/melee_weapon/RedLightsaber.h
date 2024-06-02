#pragma once
#include "../MeleeWeapon.h"

class RedLightsaber : public MeleeWeapon {
public:
    RedLightsaber(double damage = 5, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
