﻿#pragma once
#include "knife.h"

class Hammer : public Knife{
public:
    Hammer();
    Hammer(Point point);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
