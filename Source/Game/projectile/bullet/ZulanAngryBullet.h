#pragma once
#include "../Bullet.h"

class ZulanAngryBullet : public Bullet
{
public:
    ZulanAngryBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
private:
    int splitIntervalCounter;
};
