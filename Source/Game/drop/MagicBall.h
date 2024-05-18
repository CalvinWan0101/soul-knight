#pragma once
#include "MagnetizedDrop.h"

class MagicBall : public MagnetizedDrop {
public:
    MagicBall();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
};
