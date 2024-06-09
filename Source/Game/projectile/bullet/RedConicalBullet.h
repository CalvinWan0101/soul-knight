#pragma once
#include "../Bullet.h"

class RedConicalBullet : public Bullet {
public:
    RedConicalBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;

private:
    Point startPoint;
};
