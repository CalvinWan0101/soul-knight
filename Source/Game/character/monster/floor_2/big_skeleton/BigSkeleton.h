#pragma once
#include "../../../Monster.h"

class BigSkeleton : public Monster {
public:
    BigSkeleton(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;
};
