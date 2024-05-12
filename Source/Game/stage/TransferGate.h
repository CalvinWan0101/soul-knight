#pragma once
#include "../utils/object/GeneralObject.h"

class TransferGate : public GeneralObject {
public:
    TransferGate();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
};
