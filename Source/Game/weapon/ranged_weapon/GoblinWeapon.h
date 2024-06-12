#pragma once
#include "../RangedWeapon.h"

class GoblinWeapon : public RangedWeapon {
public:
    GoblinWeapon(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;

private:
    int fireCooldown;
    int bulletNumber;
    void GenerateBullets();
};
