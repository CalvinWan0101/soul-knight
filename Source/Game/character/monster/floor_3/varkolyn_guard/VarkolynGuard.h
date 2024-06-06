#pragma once
#include "../../../Monster.h"

class VarkolynGuard : public Monster {
public:
    VarkolynGuard(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    virtual void InitializeWeapon() override = 0;
};
