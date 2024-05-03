#include "stdafx.h"
#include "TransferGate.h"

#include "../manager/ObjectManager.h"
#include "../manager/StageManager.h"

TransferGate::TransferGate() {
    AddTag(Tag::TRANSFER_GATE);
}

void TransferGate::Start() {
    AddAnimation({ "resources/object/transfergate.bmp" }, RGB(255, 255, 255), 0, false);
    SetHitBoxByRatio(0.7, 0.7);
    GeneralObject::Start();
}

void TransferGate::Update() {
    GeneralObject::Update();
}

void TransferGate::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        StageManager::Instance()->NextStage();
    }
}