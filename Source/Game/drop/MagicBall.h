#pragma once
#include "Drop.h"

class MagicBall : public Drop {
public:
    MagicBall();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
};
