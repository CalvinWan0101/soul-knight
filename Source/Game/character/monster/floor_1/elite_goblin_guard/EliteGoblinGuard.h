#pragma once
#include "../../../Monster.h"

class EliteGoblinGuard : public Monster {
public:
    EliteGoblinGuard(double level);
    void Start();
    void Update();
    void LoadResources();
    void AutoMation();
};