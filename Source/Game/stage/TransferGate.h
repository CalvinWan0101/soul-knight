#pragma once
#include "../utils/InteractableDevice.h"
#include "../utils/object/GeneralObject.h"

class TransferGate : public GeneralObject, public InteractableDevice{
public:
    TransferGate();
    void Start() override;
    void Update() override;
    void LoadResources() override;

    void Interactive(Player* player) override;
};
