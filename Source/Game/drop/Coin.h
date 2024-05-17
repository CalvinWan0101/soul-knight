#pragma once
#include "MagnetizedDrop.h"

class Coin : public MagnetizedDrop {
public:
    Coin();
    enum Material {
        COPPER = 1,
        SILVER = 3,
        GOLD = 5
    };
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
    void SetValue(Material material);
private:
    int value;
};
