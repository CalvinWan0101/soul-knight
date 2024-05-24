#include "stdafx.h"
#include "Stage_3_2.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_3_2::Stage_3_2() {
    background.LoadBitmapByString({"resources/map/3-2.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    Room* room1 = new Room(Point(0, 640), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room2 = new Room(Point(592, 592), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room3 = new Room(Point(1312, 672), centerOffset, RoomSize::SMALL_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room4 = new Room(Point(640, 1280), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room5 = new Room(Point(1232, 1232), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(687, 31) - centerOffset);
    }
}

void Stage_3_2::GenerateWall() {
    AddWall(Point(640, 1), Point(656, 272));
    AddWall(Point(640, 1), Point(912, 15));
    AddWall(Point(896, 1), Point(912, 272));
    AddWall(Point(592, 256), Point(735, 608));
    AddWall(Point(816, 256), Point(960, 607));
    AddWall(Point(256, 592), Point(608, 735));
    AddWall(Point(256, 816), Point(608, 961));
    AddWall(Point(1, 640), Point(271, 655));
    AddWall(Point(1, 640), Point(15, 912));
    AddWall(Point(1, 896), Point(272, 912));
    AddWall(Point(943, 592), Point(1327, 735));
    AddWall(Point(944, 817), Point(1327, 960));
    AddWall(Point(1312, 672), Point(1520, 687));
    AddWall(Point(1504, 672), Point(1520, 880));
    AddWall(Point(1232, 864), Point(1376, 1248));
    AddWall(Point(1456, 864), Point(1600, 1247));
    AddWall(Point(1584, 1232), Point(1600, 1599));
    AddWall(Point(1233, 1584), Point(1600, 1599));
    AddWall(Point(896, 1232), Point(1248, 1375));
    AddWall(Point(895, 1456), Point(1248, 1600));
    AddWall(Point(592, 944), Point(736, 1295));
    AddWall(Point(816, 944), Point(960, 1295));
    AddWall(Point(640, 1536), Point(912, 1552));
    AddWall(Point(304, 1456), Point(656, 1552));
    AddWall(Point(304, 1280), Point(656, 1376));
    AddWall(Point(112, 1312), Point(320, 1329));
    AddWall(Point(112, 1313), Point(128, 1520));
    AddWall(Point(112, 1504), Point(320, 1520));
}

void Stage_3_2::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(775, 135) - centerOffset);
}

void Stage_3_2::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(215, 1415) - centerOffset);
}

void Stage_3_2::GenerateObstacle() {
}
