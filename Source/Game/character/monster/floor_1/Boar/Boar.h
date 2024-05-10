#pragma once
#include "../../../Monster.h"
#include "../../../../projectile/Projectile.h"

class Boar : public Monster, public Projectile{
public:
    Boar(double level);
    virtual void Start() override;
    void Update() override;
    void AutoMation() override;
    void DumpState(bool isDump);
private:
    int angryCounter;
    int calmCounter;
    int angryKeepFrame;
    int clamKeepFrame;
    bool isAngry;
};
