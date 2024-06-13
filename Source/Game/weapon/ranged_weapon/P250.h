#pragma once
#include "../RangedWeapon.h"

class Point;

class P250 : public RangedWeapon {
public:
    P250(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;

private:
    void GeneratePlayerBullet();
    void GenerateMonsterBullet();
};
