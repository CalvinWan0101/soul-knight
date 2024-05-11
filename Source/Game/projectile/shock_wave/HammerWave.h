#pragma once
#include "../ShockWave.h"

class HammerWave : public ShockWave{
public:
    HammerWave();
    void Start() override;
    void Update() override;
};
