#pragma once
#include "gun.h"

class BadPistol : public Gun {
public:
    BadPistol();
    BadPistol(Point point);
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void Attack() override;
};
