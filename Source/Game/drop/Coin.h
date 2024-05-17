#pragma once
#include "MagnetizedDrop.h"

class Coin : public MagnetizedDrop {
public:
    Coin();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
    void SetValue(int value);
private:
    int value;
};
