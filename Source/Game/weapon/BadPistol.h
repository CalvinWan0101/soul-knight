#pragma once
#include "gun.h"

class BadPistol : public Gun
{
public:
    BadPistol();
    void Start() override;
    void Update() override;
    void Attack() override;
};
