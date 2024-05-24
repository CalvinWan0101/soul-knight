#include "stdafx.h"
#include "Stage_1_2.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_1_2::Stage_1_2() {
    background.LoadBitmapByString({"resources/map/1-2.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    Room* room1 = new Room(Point(592, 0), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room2 = new Room(Point(1280, 80), centerOffset, RoomSize::SMALL_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room3 = new Room(Point(640, 688), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(47, 79) - centerOffset);
    }
}

void Stage_1_2::GenerateWall() {
    AddWall(Point(0, 48), Point(271, 63));
    AddWall(Point(0, 48), Point(15, 319));
    AddWall(Point(0, 304), Point(271, 319));
    AddWall(Point(256, 143), Point(607, 0));
    AddWall(Point(256, 224), Point(607, 367));
    AddWall(Point(592, 0), Point(959, 15));
    AddWall(Point(944, 0), Point(1295, 143));
    AddWall(Point(944, 367), Point(1295, 224));
    AddWall(Point(1280, 80), Point(1487, 95));
    AddWall(Point(1472, 80), Point(1487, 287));
    AddWall(Point(1280, 272), Point(1487, 287));
    AddWall(Point(592, 352), Point(735, 703));
    AddWall(Point(816, 703), Point(959, 352));
    AddWall(Point(656, 688), Point(304, 783));
    AddWall(Point(304, 864), Point(655, 959));
    AddWall(Point(896, 688), Point(911, 959));
    AddWall(Point(640, 944), Point(911, 959));
    AddWall(Point(112, 720), Point(319, 735));
    AddWall(Point(112, 720), Point(127, 927));
    AddWall(Point(112, 921), Point(319, 927));
}

void Stage_1_2::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(135, 183) - centerOffset);
}

void Stage_1_2::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(215, 823) - centerOffset);
}

void Stage_1_2::GenerateObstacle() {
}
