#pragma once
#include "game_object.h"

class TransferGate : public game_framework::GameObject {
public:
    TransferGate();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
};
