#include "stdafx.h"
#include "Stage.h"

#include "../utils/Rand.h"
#include "../manager/ObjectManager.h"
#include "../manager/StageManager.h"
#include "../shop/WeaponVendingMachine.h"
#include "../shop/PotionVendingMachine.h"
#include "../shop/TreasureChest.h"
#include "../wall/Wall.h"

Stage::Stage() {
    int level = StageManager::Instance()->GetLevelNumber();
    int stage = StageManager::Instance()->GetStageNumber();

    // vending machine
    switch (Rand::Instance()->Get(0, 2)) {
    case 0:
        vendingMachine = new WeaponVendingMachine(level, stage);
        break;
    case 1:
        vendingMachine = new PotionVendingMachine(level, stage);
        break;
    default:
        vendingMachine = nullptr;
    }
    if (vendingMachine) {
        ObjectManager::Instance()->AddObject(vendingMachine);
    }
}

Stage::~Stage() {
    for (auto room : rooms) {
        delete room;
    }
    for (auto wall : walls) {
        wall->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    if (vendingMachine) {
        vendingMachine->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

game_framework::CMovingBitmap* Stage::GetBackground() {
    return &background;
}

void Stage::Initialize() {
    GenerateWall();
    SetPlayerPosition();
    SetTransferGate();
    GenerateObstacle();
}

void Stage::Show(Point screenPositoin) {
    background.SetTopLeft(static_cast<int>(-screenPositoin.GetX() - static_cast<double>(background.GetWidth()) / 2),
                          static_cast<int>(-screenPositoin.GetY() - static_cast<double>(background.GetHeight()) / 2));
    background.ShowBitmap();
}

void Stage::AddWall(Point point1, Point point2) {
    Wall* wall = new Wall(point1 - centerOffset, point2 - centerOffset);
    walls.push_back(wall);
    ObjectManager::Instance()->AddObject(wall);
}

void Stage::IsInsideRoom() {
    for (auto room : rooms) {
        room->IsInside();
    }
}

void Stage::IsRoomCleared() {
    for (auto room : rooms) {
        room->IsCleared();
    }
}
