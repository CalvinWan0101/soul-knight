#pragma once
#include "Drop.h"

class Coin : public Drop {
public:
    Coin();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
private:
    int value;
};
