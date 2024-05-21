#include "stdafx.h"
#include "PotionVendingMachine.h"

#include "../collectable/PotionFactory.h"
#include "../manager/ObjectManager.h"
#include "../utils/Rand.h"

PotionVendingMachine::PotionVendingMachine(int level, int stage) : VendingMachine(level, stage) {
}

void PotionVendingMachine::Shipment() {
    int potionId = Rand::Instance()->Get(0, static_cast<int>(PotionFactory::PotionType::Count) - 1);
    Collectable* collectable = PotionFactory::Create(static_cast<PotionFactory::PotionType>(potionId));
    collectable->SetPosition(this->position + Point(0, 45));
    ObjectManager::Instance()->AddObject(collectable);
}

void PotionVendingMachine::LoadResources() {
    AddAnimation({"Resources/shop/potion_vending_machine.bmp"}, RGB(255,255,255), 1000, false);
}