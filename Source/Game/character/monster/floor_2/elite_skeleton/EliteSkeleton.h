#pragma once
#include "../../../Monster.h"

class EliteSkeleton : public Monster {
public:
    EliteSkeleton(double level, bool isMeleeAttackMonster = false);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    virtual void InitializeWeapon() override = 0;
};
