#pragma once
#include "weapon.h"

class Knife : public Weapon{
public:
    Knife();
    Knife(Point point);
    void Start() override;
    void Update() override;
    void Attack() override = 0;
};
