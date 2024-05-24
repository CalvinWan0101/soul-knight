#include "stdafx.h"
#include "Stage_2_2.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_2_2::Stage_2_2() {
    background.LoadBitmapByString({"resources/map/2-2.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    MonsterRoom* room1 = new MonsterRoom(Point(640, 48), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room2 = new MonsterRoom(Point(1232, 0), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room3 = new MonsterRoom(Point(592, 640), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room4 = new MonsterRoom(Point(1312, 720), centerOffset, RoomSize::SMALL_SIZE, 4,
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

void Stage_2_2::GenerateWall() {
    AddWall(Point(304, 224), Point(655, 320));
    AddWall(Point(304, 48), Point(656, 143));
    AddWall(Point(112, 80), Point(320, 95));
    AddWall(Point(112, 80), Point(127, 288));
    AddWall(Point(112, 272), Point(320, 288));
    AddWall(Point(640, 48), Point(912, 64));
    AddWall(Point(897, 1), Point(1247, 142));
    AddWall(Point(896, 224), Point(1247, 368));
    AddWall(Point(592, 305), Point(736, 655));
    AddWall(Point(816, 304), Point(960, 655));
    AddWall(Point(1232, 1), Point(1600, 14));
    AddWall(Point(1584, 1), Point(1600, 368));
    AddWall(Point(1456, 352), Point(1600, 735));
    AddWall(Point(1232, 352), Point(1375, 735));
    AddWall(Point(944, 640), Point(1327, 783));
    AddWall(Point(944, 864), Point(1328, 1008));
    AddWall(Point(1312, 912), Point(1520, 928));
    AddWall(Point(1504, 720), Point(1520, 928));
    AddWall(Point(256, 640), Point(608, 783));
    AddWall(Point(256, 864), Point(608, 1008));
    AddWall(Point(1, 688), Point(272, 704));
    AddWall(Point(1, 944), Point(272, 960));
    AddWall(Point(1, 688), Point(15, 959));
    AddWall(Point(592, 992), Point(735, 1343));
    AddWall(Point(816, 992), Point(960, 1343));
    AddWall(Point(640, 1328), Point(655, 1600));
    AddWall(Point(640, 1584), Point(912, 1600));
    AddWall(Point(896, 1329), Point(912, 1600));
}

void Stage_2_2::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(135, 822) - centerOffset);
}

void Stage_2_2::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(215, 183) - centerOffset);
}

void Stage_2_2::GenerateObstacle() {
}
