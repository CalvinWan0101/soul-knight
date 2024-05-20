#include "stdafx.h"
#include "TransferGate.h"

#include "../manager/ObjectManager.h"
#include "../manager/StageManager.h"

TransferGate::TransferGate() {
    AddTag(Tag::TRANSFER_GATE);
    SetInteractiveText("Transfer ?", InteractiveText::COMMON, -80);
}

void TransferGate::Start() {
    GeneralObject::Start();
    SetHitBoxByRatio(0.7, 0.7);
}

void TransferGate::Update() {
    GeneralObject::Update();
}

void TransferGate::LoadResources() {
    AddAnimation({"resources/object/transfer_gate/transfergate.bmp"}, RGB(255, 255, 255), 0, false);
}

void TransferGate::Interactive(Player* player) {
    StageManager::Instance()->NextStage();
}
