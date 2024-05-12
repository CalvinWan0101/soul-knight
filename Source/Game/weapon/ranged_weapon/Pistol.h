#pragma once
#include "../RangedWeapon.h"

class Point;

class Pistol : public RangedWeapon {
public:
    Pistol(Point point);
    Pistol(double damage = 3);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
