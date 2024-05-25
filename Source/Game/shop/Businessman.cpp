#include "stdafx.h"
#include "Businessman.h"

#include "DisplayStand.h"
#include "../manager/ObjectManager.h"
#include "../utils/Rand.h"

Businessman::Businessman(int level, int stage) : level(level), stage(stage) {
}


void Businessman::Start() {
    GeneralObject::Start();
    SetInteractiveText("Unmysterious businessman", InteractiveText::COMMON, -40);
    SetHitBoxByRatio(1,1);
    DisplayStand* displayStand;
    int displayStandCount = Rand::Instance()->Get(2,4);
    double step = 140 / static_cast<double>(displayStandCount - 1);
    for (int i = 0; i < displayStandCount; i++) {
        displayStand = new DisplayStand(level, stage);
        displayStand->SetPosition(this->position + Point(-70 + i * step, 50));
        ObjectManager::Instance()->AddObject(displayStand);
    }
}

void Businessman::LoadResources() {
    AddAnimation({"Resources/shop/businessman.bmp"}, RGB(255,255,255), 1000, false);
}

void Businessman::Interactive(Player* player) {
}


