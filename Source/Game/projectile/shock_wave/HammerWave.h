#pragma once
#include "../ShockWave.h"

class HammerWave : public ShockWave{
public:
    void Start() override;
    void Update() override;
};
