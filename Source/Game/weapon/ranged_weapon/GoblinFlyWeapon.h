#pragma once
#include "../RangedWeapon.h"

class GoblinFlyWeapon : public RangedWeapon {
public:
    GoblinFlyWeapon(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;

private:
    void GenerateBullets();
};
