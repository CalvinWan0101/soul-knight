#pragma once
#include "../ShockWave.h"

class BlowUp : public ShockWave{
public:
    BlowUp();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
