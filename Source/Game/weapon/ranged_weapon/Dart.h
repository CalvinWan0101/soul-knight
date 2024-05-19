#pragma once
#include "../RangedWeapon.h"

class Point;

class Dart : public RangedWeapon {
public:
    Dart(Point point);
    Dart(double damage = 6);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
