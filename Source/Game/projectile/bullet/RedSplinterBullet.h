#pragma once
#include "../Bullet.h"

class RedSplinterBullet : public Bullet {
public:
    RedSplinterBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
private:
    Point startPoint;
};
