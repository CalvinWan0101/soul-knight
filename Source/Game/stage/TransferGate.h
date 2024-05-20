#pragma once
#include "../utils/Interactable.h"
#include "../utils/object/GeneralObject.h"

class TransferGate : public GeneralObject, public Interactable{
public:
    TransferGate();
    void Start() override;
    void Update() override;
    void LoadResources() override;

    void Interactive(Player* player) override;
};
