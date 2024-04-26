#pragma once
#include "shock_wave.h"

class Wave : public ShockWave{
public:
    void Start() override;
    void Update() override;
};
