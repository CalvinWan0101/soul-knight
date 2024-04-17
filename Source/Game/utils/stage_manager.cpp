#include "stdafx.h"
#include "stage_manager.h"
#include <iostream>

#include "object_manager.h"
#include "stage_factory.h"
#include "../character/player/player.h"

StageManager* StageManager::instance = nullptr;

StageManager* StageManager::Instance() {
    if (instance == nullptr) {
        instance = new StageManager();
    }
    return instance;
}

StageManager::StageManager() {
    level = 0;
    stage = 5;
}

StageManager::~StageManager() {
    delete gameStage;
}

void StageManager::Update() {
    gameStage->DetectRoom1();
    gameStage->DetectRoom2();
    gameStage->DetectRoom1Cleared();
    gameStage->DetectRoom2Cleared();
}

Stage* StageManager::GetStage() {
    return gameStage;
}

void StageManager::Initiliaze() {
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
    
    gameStage = StageFactory::Create(level, stage);

    // For testing
    if (!gameStage) {
        gameStage = new Stage_1_1();
    }

    gameStage->Initialize();

    std::cout << "Level: " << level << " Stage: " << stage << "\n";
}

bool StageManager::InRoom() {
    return inRoom;
}
