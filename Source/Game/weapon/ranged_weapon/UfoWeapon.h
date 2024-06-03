#pragma once
#include "../RangedWeapon.h"

class UfoWeapon : public RangedWeapon {
public:
    UfoWeapon(double damage = 3, Point position = {0, 0});
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
