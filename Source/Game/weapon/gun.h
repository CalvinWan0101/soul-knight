#pragma once
#include "weapon.h"
#include "../utils/rotatable_object.h"

class Gun : public Weapon {
public:
    Gun();
    void Start() override;
    void Update() override;
    void Attack() override = 0;
};
