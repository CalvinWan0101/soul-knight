#pragma once
#include "Alien.h"

class AlienMachineGun : public Alien {
public:
    AlienMachineGun(double level);
    void Start() override;
    void InitializeWeapon() override;
};
