#pragma once
#include "Alien.h"

class AlienRedLightsaber : public Alien {
public:
    AlienRedLightsaber(double level);
    void Start() override;
    void InitializeWeapon() override;
};
