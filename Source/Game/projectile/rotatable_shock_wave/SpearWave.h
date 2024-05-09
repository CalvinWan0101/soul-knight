#pragma once
#include "../RotatableShockWave.h"

class SpearWave : public RotatableShockWave {
public:
    void Start() override;
    void Update() override;
};
