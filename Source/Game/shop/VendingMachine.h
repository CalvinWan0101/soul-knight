#pragma once
#include "../utils/Interactable.h"
#include "../utils/object/GeneralObject.h"

class VendingMachine : public GeneralObject, public Interactable{
public:
    VendingMachine(int stage, int level);
    ~VendingMachine();
    void Start() override;
    void Update() override;

    void Interactive(Player* player) override;

    virtual void Shipment() = 0;
    
private:
    int price;
    int remainingTime;
    bool isShipment;
};
