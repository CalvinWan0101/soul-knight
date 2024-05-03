#pragma once
#include "../Bullet.h"

class BadPistolBullet : public Bullet {
public:
    BadPistolBullet();
    void Start() override;
    void Update() override;
};
