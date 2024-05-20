#include "stdafx.h"
#include "VendingMachine.h"

#include "../manager/ObjectManager.h"

VendingMachine::VendingMachine(int stage, int level) {
    price = level * 20 + (rand() % stage * 3) - stage * 3 / 2;
    SetInteractiveText(std::to_string(price), InteractiveText::LEGENDARY, -45);
}

VendingMachine::~VendingMachine() {
    
}

void VendingMachine::Start() {
    GeneralObject::Start();
    SetHitBoxByRatio(1, 1);
    remainingTime = rand() % 3 + 4;
    isShipment = false;
}

void VendingMachine::Update() {
    GeneralObject::Update();
}

void VendingMachine::Interactive(Player* player) {
    if (remainingTime > 0 && ObjectManager::Instance()->SpendMoney(price)) {
        if (rand() % (remainingTime + 1) == 0) {
            isShipment = true;
            Shipment();
        }
        remainingTime--;
        if (remainingTime == 0) {
            SetInteractiveText("Sold out", InteractiveText::COMMON, -45);
            if (isShipment == false) {
                Shipment();
            }
        }
    }
}
