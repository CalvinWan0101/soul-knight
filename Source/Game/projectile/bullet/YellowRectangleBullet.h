#pragma once
#include "../Bullet.h"

class YellowRectangleBullet : public Bullet {
public:
    YellowRectangleBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
