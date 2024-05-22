#pragma once
#include "../RangedWeapon.h"

class Point;

class Dart : public RangedWeapon {
public:
    Dart(double damage = 6, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
