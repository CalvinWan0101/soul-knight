#pragma once
#include "../Bullet.h"

class SpiralBullet : public Bullet
{
public:
    SpiralBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
private:
    int splitIntervalCounter;
    Vec splitAngle;
};
