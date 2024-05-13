#pragma once
#include "../Bullet.h"

class RedDiamondBullet : public Bullet{
public:
    RedDiamondBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
