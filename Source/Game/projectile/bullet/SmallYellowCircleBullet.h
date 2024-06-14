#pragma once
#include "../Bullet.h"

class SmallYellowCircleBullet : public Bullet {
public:
    SmallYellowCircleBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
