#pragma once
#include "../Bullet.h"

class RedHollowCircleBullet : public Bullet {
public:
    RedHollowCircleBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;

private:
    Point startPoint;
};
