#pragma once
#include "general_object.h"

class TransferGate : public game_framework::GeneralObject {
public:
    TransferGate();
    void Start() override;
    void Update() override;
    void Collision(GeneralObject* generalObject) override;
};
