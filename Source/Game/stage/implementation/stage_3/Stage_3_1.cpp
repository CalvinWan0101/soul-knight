#include "stdafx.h"
#include "Stage_3_1.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_3_1::Stage_3_1() {
    background.LoadBitmapByString({"resources/map/3-1.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    Room* room1 = new Room(Point(), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room2 = new Room(Point(), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room3 = new Room(Point(), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room4 = new Room(Point(), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room5 = new Room(Point(), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);
}

void Stage_3_1::GenerateWall() {
}

void Stage_3_1::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point() - centerOffset);
}

void Stage_3_1::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point() - centerOffset);
}

void Stage_3_1::GenerateObstacle() {
}
