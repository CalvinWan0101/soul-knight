#pragma once
#include "../Bullet.h"

class GreenRectangleBullet : public Bullet {
public:
    GreenRectangleBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
