#pragma once
#include "weapon.h"
#include "../utils/rotatable_object.h"

class Gun : public Weapon {
public:
    Gun();
    void Start() override = 0;
    void Update() override = 0;
    void Attack() override = 0;
};
