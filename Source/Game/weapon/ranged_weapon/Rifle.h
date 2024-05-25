#pragma once
#include "../RangedWeapon.h"

class Rifle : public RangedWeapon {
public:
    Rifle(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;

private:
    void GenerateBullets(bool isPlayer);
};
