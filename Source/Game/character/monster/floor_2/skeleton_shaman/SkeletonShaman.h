#pragma once
#include "../../../Monster.h"

class SkeletonShaman : public Monster {
public:
    SkeletonShaman(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;
};
