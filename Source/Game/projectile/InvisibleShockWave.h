#pragma once
#include "Projectile.h"
#include "../utils/object/InvisibleObject.h"

class InvisibleShockWave : public InvisibleObject, public Projectile{
public:
    InvisibleShockWave();
    void Start() override;
    void Update() override;
    void SetAliveTime(double second);
    void SetSize(double size);
private:
    int aliveFrame;
    bool activicated;
};
