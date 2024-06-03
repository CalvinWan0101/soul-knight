#pragma once
#include "../../../Monster.h"

class Alien : public Monster {
public:
    Alien(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    virtual void InitializeWeapon() override = 0;
};
