#pragma once
#include "../../../Monster.h"

class Battery : public Monster {
public:
    Battery(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;
};
