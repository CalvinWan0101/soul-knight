#pragma once
#include "../utils/rotatable_object.h"

class Weapon : public RotatableObject {
public:
    Weapon();
    void Start() override = 0;
    void Update() override = 0;
    virtual void Attack() = 0;
    int GetCd();
    int GetDamage();
    int GetMpCost();

private:
    int cd;
    int damage;
    int mpCost;
};
