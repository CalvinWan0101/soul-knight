#pragma once
#include "../Bullet.h"

class GasBlasterBullet : public Bullet {
public:
    GasBlasterBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
