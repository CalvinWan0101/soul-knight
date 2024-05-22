#pragma once
#include "../RangedWeapon.h"

class Bullet;

class Shotgun : public RangedWeapon {
public:
    Shotgun(double damage = 3, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
private:
    void GeneratePlayerBullet();
    void GenerateMonsterBullet();
};
