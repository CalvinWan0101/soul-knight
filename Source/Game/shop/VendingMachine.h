#pragma once
#include "../utils/InteractableDevice.h"
#include "../utils/object/GeneralObject.h"

class VendingMachine : public GeneralObject, public InteractableDevice{
public:
    VendingMachine(int level, int stage);
    virtual ~VendingMachine();
    void Start() override;
    void Update() override;

    void Interactive(Player* player) override;

    virtual void Shipment() = 0;
    
private:
    int price;
    int remainingTime;
    bool isShipment;
};
