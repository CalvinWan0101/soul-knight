#pragma once
#include "../../../Monster.h"

class GoblinGuard : public Monster {
public:
    GoblinGuard(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    virtual void InitializeWeapon() override = 0;
};
