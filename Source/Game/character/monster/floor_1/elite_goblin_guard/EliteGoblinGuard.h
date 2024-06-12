#pragma once
#include "../../../Monster.h"

class EliteGoblinGuard : public Monster {
public:
    EliteGoblinGuard(double level, bool isMeleeAttackMonster = false);
    void Start();
    void Update();
    void LoadResources();
    void AutoMation();
    virtual void InitializeWeapon() override = 0;
};
