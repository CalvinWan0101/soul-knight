#pragma once
#include "../../Monster.h"

class GoblinGiant : public Monster {
public:
    GoblinGiant();
    GoblinGiant(double level);
    void Start() override;
    void Update() override;
};
