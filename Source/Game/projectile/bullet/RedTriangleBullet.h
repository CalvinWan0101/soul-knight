#pragma once
#include "../Bullet.h"

class RedTriangleBullet : public Bullet {
public:
    RedTriangleBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
