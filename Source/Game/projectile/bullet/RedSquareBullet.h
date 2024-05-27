#pragma once
#include "../Bullet.h"

class RedSquareBullet : public Bullet {
public:
    RedSquareBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
