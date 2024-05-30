#pragma once
#include "../Bullet.h"

class BigRedCircleBullet : public Bullet {
public:
    BigRedCircleBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
};
