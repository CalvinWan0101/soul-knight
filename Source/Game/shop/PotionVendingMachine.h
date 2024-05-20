#pragma once
#include "VendingMachine.h"

class PotionVendingMachine : public VendingMachine{
public:
    PotionVendingMachine(int stage, int level);
    void Shipment() override;
    void LoadResources() override;
};
