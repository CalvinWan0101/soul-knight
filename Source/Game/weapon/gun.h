#pragma once
#include "weapon.h"

class Gun : public Weapon
{
public:
    Gun();
    void Start() override = 0;
    void Update() override = 0;
    void Attack() override = 0;
    void Rotate(double radian);
    void SetRotation(Vec* radian);
    Vec GetRotation() const;
private:
    Vec rotation;
};
