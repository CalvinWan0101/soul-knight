#pragma once
#include "../RangedWeapon.h"

class Point;

class Pistol : public RangedWeapon {
public:
    Pistol(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;

private:
    void GeneratePlayerBullet();
    void GenerateMonsterBullet();
};
