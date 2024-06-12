#pragma once
#include "../../../Monster.h"

class GoblinFly : public Monster {
public:
    GoblinFly(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;
};
