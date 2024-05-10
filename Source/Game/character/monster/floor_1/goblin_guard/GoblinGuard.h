#pragma once
#include "../../../Monster.h"

class GoblinGuard : public Monster {
public:
    GoblinGuard(double level);
    virtual void Start() override;
    void Update() override;
};
