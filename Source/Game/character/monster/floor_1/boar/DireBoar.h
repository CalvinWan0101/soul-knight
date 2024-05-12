#pragma once
#include "Boar.h"

class DireBoar : public Boar {
public:
    DireBoar(double level);
    void Start() override;
    void LoadResources() override;
};
