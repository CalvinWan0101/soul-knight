#pragma once
#include "VendingMachine.h"

class WeaponVendingMachine : public VendingMachine{
public:
    WeaponVendingMachine(int level, int stage);
    void Shipment() override;
    void LoadResources() override;
};