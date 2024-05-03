#pragma once
#include "../shock_wave.h"

class HammerWave : public ShockWave{
public:
    void Start() override;
    void Update() override;
};
