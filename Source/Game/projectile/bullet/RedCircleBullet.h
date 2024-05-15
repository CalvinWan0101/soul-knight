#pragma once
#include "../Bullet.h"

class RedCircleBullet : public Bullet{
public:
    RedCircleBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
