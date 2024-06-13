#pragma once
#include "../Bullet.h"

class SplitterCannonBullet : public Bullet {
public:
    SplitterCannonBullet();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
    void SetSplit(bool isSplit);
    void OnRemove() override;

private:
    bool isSplit;
};
