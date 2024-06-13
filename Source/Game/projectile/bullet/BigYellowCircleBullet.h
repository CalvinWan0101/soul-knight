#pragma once
#include "../Bullet.h"

class BigYellowCircleBullet : public Bullet {
public:
    BigYellowCircleBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
    void SetSplit(bool isSplit);
    void OnRemove() override;

private:
    bool isSplit;
};
