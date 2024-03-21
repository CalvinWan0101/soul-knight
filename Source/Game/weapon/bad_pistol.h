#pragma once
#include "gun.h"

class BadPistol : public Gun
{
public:
    double i = 0;
    BadPistol();
    void Start() override;
    void Update() override;
    void Attack() override;
};
