#include "stdafx.h"
#include "VendingMachine.h"

#include "../manager/ObjectManager.h"
#include "../utils/Rand.h"

VendingMachine::VendingMachine(int level, int stage) {
    price = level * 20 + Rand::Instance()->Get(stage * -3, stage * 3);
    SetInteractiveText(std::to_string(price), InteractiveText::LEGENDARY, -45);
}

VendingMachine::~VendingMachine() {
    
}

void VendingMachine::Start() {
    GeneralObject::Start();
    SetHitBoxByRatio(1, 1);
    remainingTime = Rand::Instance()->Get(4,7);
    isShipment = false;
}

void VendingMachine::Update() {
    GeneralObject::Update();
}

void VendingMachine::Interactive(Player* player) {
    if (remainingTime > 0 && ObjectManager::Instance()->SpendMoney(price)) {
        if (Rand::Instance()->Get(0,remainingTime + 1) == 0) {
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
