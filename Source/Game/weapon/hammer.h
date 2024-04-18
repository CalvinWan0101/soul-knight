#pragma once
#include "knife.h"

class Hammer : public Knife{
public:
    Hammer();
    void Start() override;
    void Update() override;
    void Attack() override;
};
