#pragma once
#include "../../../Monster.h"

class Goblin : public Monster {
public:
    Goblin(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;
};
