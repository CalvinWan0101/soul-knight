#include "stdafx.h"
#include "StageManager.h"
#include <iostream>

#include "ObjectManager.h"
#include "../stage/StageFactory.h"
#include "../character/Player.h"

StageManager* StageManager::instance = nullptr;

StageManager* StageManager::Instance() {
    if (instance == nullptr) {
        instance = new StageManager();
    }
    return instance;
}

StageManager::StageManager(): level(0), stage(5) {
}

StageManager::~StageManager() {
    delete gameStage;
}

void StageManager::Update() {
    gameStage->IsInsideRoom();
    gameStage->IsRoomCleared();
}

Stage* StageManager::GetStage() {
    return gameStage;
}

void StageManager::Initiliaze() {
    transferGate = new TransferGate();
    transferGate->SetPosition(Point(0, 0));
    ObjectManager::Instance()->AddObject(transferGate);
    NextStage();
}

void StageManager::NextStage() {
    stage++;
    if (stage > 5 && level != 3) {
        stage = 1;
        level++;
    }

    // For testing
    if (level == 3 && stage > 6) {
        level = 1;
        stage = 1;
    }

    if (gameStage) {
        gameStage->ClearedStage();
        delete gameStage;
    }

    gameStage = StageFactory::Create(level, stage);

    // For testing
    if (!gameStage) {
        gameStage = new Stage_1_1();
    }

    gameStage->Initialize();

    std::cout << "Level: " << level << " Stage: " << stage << "\n";
}

void StageManager::SetTransferGatePosition(Point position) {
    transferGate->SetPosition(position);
}
