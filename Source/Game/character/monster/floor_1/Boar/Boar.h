#pragma once
#include "../../../Monster.h"

class Boar : public Monster{
public:
    Boar(double level);
    virtual void Start() override;
    void Update() override;
};
