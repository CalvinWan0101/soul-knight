#include "stdafx.h"
#include "stage_manager.h"
#include <iostream>

#include "object_manager.h"
#include "../character/player/player.h"

StageManager* StageManager::instance = nullptr;

StageManager* StageManager::Instance() {
    if (instance == nullptr) {
        instance = new StageManager();
    }
    return instance;
}

StageManager::StageManager() {
    level = 1;
    stage = 5;
}

StageManager::~StageManager() {
}

int StageManager::GetLevel() {
    return level;
}

int StageManager::GetStage() {
    return stage;
}

void StageManager::Initiliaze() {
    ObjectManager::Instance()->UpdateGameMap(level, stage);
    UpdatePlayerPosition();
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

    ObjectManager::Instance()->UpdateGameMap(level, stage);
    UpdatePlayerPosition();

    std::cout << "Level: " << level << " Stage: " << stage << std::endl;
}

void StageManager::UpdatePlayerPosition() {
    Player* player = ObjectManager::Instance()->GetPlayer();
    TransferGate* transferGate = ObjectManager::Instance()->GetTransferGate();
    if (1 == level) {
        if (stage == 1) {
            transferGate->SetPoint(-900, -300);
            player->SetPoint(345, 300);
        }
        else if (stage == 2) {
            transferGate->SetPoint(-790, 340);
            player->SetPoint(-875, -300);
        }
        else if (stage == 3) {
            transferGate->SetPoint(330, 340);
            player->SetPoint(410, 980);
        }
        else if (stage == 4) {
            transferGate->SetPoint(-230, -220);
            player->SetPoint(330, 340);
        }
        else if (stage == 5) {
            transferGate->SetPoint(-825, 245);
            player->SetPoint(-190, -340);
        }
    }
}
