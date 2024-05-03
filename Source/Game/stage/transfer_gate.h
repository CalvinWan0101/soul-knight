#pragma once
#include "../utils/object/general_object.h"

class TransferGate : public GeneralObject {
public:
    TransferGate();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
};
