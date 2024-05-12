#pragma once
#include "Boar.h"

class NormalBoar : public Boar{
public:
    NormalBoar(double level);
    void Start() override;
    void LoadResources() override;
};
