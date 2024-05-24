#include "stdafx.h"
#include "Stage_3_4.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../../room/RoomSize.h"

Stage_3_4::Stage_3_4() {
    background.LoadBitmapByString({"resources/map/3-4.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    MonsterRoom* room1 = new MonsterRoom(Point(672, 80), centerOffset, RoomSize::SMALL_SIZE, 4,
                                         std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room2 = new MonsterRoom(Point(1232, 0), centerOffset, RoomSize::LARGE_SIZE, 4,
                                         std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room3 = new MonsterRoom(Point(592, 640), centerOffset, RoomSize::LARGE_SIZE, 4,
                                         std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room4 = new MonsterRoom(Point(1280, 688), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                                         std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room5 = new MonsterRoom(Point(640, 1328), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                                         std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(47, 719) - centerOffset);
    }
}

void Stage_3_4::GenerateWall() {
    AddWall(Point(864, 1), Point(1248, 144));
    AddWall(Point(864, 224), Point(1248, 368));
    AddWall(Point(672, 80), Point(880, 95));
    AddWall(Point(672, 80), Point(688, 288));
    AddWall(Point(593, 272), Point(735, 656));
    AddWall(Point(816, 272), Point(960, 655));
    AddWall(Point(1232, 1), Point(1600, 15));
    AddWall(Point(1584, 1), Point(1600, 368));
    AddWall(Point(1232, 352), Point(1375, 703));
    AddWall(Point(1456, 352), Point(1600, 703));
    AddWall(Point(1535, 688), Point(1552, 960));
    AddWall(Point(1280, 944), Point(1375, 1295));
    AddWall(Point(1457, 944), Point(1552, 1296));
    AddWall(Point(1312, 1280), Point(1328, 1488));
    AddWall(Point(1503, 1280), Point(1520, 1488));
    AddWall(Point(1312, 1472), Point(1520, 1488));
    AddWall(Point(944, 640), Point(1295, 783));
    AddWall(Point(944, 863), Point(1295, 1008));
    AddWall(Point(256, 640), Point(608, 784));
    AddWall(Point(256, 864), Point(608, 1008));
    AddWall(Point(1, 688), Point(272, 703));
    AddWall(Point(1, 688), Point(16, 961));
    AddWall(Point(1, 944), Point(272, 961));
    AddWall(Point(592, 992), Point(736, 1344));
    AddWall(Point(816, 992), Point(960, 1344));
    AddWall(Point(640, 1328), Point(656, 1600));
    AddWall(Point(640, 1584), Point(912, 1600));
    AddWall(Point(896, 1328), Point(912, 1600));
}

void Stage_3_4::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(135, 824) - centerOffset);
}

void Stage_3_4::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(1415, 1383) - centerOffset);
}

void Stage_3_4::GenerateObstacle() {
}
