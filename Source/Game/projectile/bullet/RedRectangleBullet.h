#pragma once
#include "../Bullet.h"

class RedRectangleBullet : public Bullet {
public:
    RedRectangleBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
