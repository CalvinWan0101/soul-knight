#pragma once
#include "Projectile.h"
#include "../utils/object/RotatableObject.h"

class RotatableShockWave : public RotatableObject, public Projectile{
public:
    void Start() override;
    void Update() override;
    void SetAliveTime(double second);
private:
    int aliveFrame;
    bool activicated;
};
