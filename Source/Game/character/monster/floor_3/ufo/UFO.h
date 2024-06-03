#pragma once
#include "../../../Monster.h"

class UFO : public Monster {
public:
    UFO(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;
};
