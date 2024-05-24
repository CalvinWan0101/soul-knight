#include "stdafx.h"
#include "Stage_3_3.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_3_3::Stage_3_3() {
    background.LoadBitmapByString({"resources/map/3-3.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    Room* room1 = new Room(Point(32, 32), centerOffset, RoomSize::SMALL_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room2 = new Room(Point(640, 0), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room3 = new Room(Point(0, 640), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room4 = new Room(Point(592, 592), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room5 = new Room(Point(1280, 640), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(687, 1311) - centerOffset);
    }
}

void Stage_3_3::GenerateWall() {
    AddWall(Point(31, 31), Point(46, 239));
    AddWall(Point(31, 31), Point(239, 46));
    AddWall(Point(224, 1), Point(655, 94));
    AddWall(Point(223, 176), Point(655, 272));
    AddWall(Point(640, 1), Point(912, 16));
    AddWall(Point(896, 1), Point(1247, 95));
    AddWall(Point(896, 176), Point(1247, 272));
    AddWall(Point(1232, 32), Point(1440, 48));
    AddWall(Point(1230, 224), Point(1440, 240));
    AddWall(Point(1423, 32), Point(1440, 240));
    AddWall(Point(593, 257), Point(735, 607));
    AddWall(Point(816, 256), Point(960, 607));
    AddWall(Point(256, 592), Point(608, 735));
    AddWall(Point(176, 224), Point(272, 655));
    AddWall(Point(1, 223), Point(96, 656));
    AddWall(Point(1, 641), Point(15, 912));
    AddWall(Point(1, 895), Point(272, 912));
    AddWall(Point(256, 816), Point(608, 960));
    AddWall(Point(943, 593), Point(1295, 736));
    AddWall(Point(944, 816), Point(1296, 959));
    AddWall(Point(1280, 640), Point(1552, 655));
    AddWall(Point(1536, 641), Point(1552, 912));
    AddWall(Point(1281, 896), Point(1552, 912));
    AddWall(Point(592, 944), Point(735, 1295));
    AddWall(Point(816, 945), Point(960, 1295));
    AddWall(Point(640, 1280), Point(655, 1552));
    AddWall(Point(896, 1280), Point(912, 1552));
    AddWall(Point(640, 1537), Point(913, 1552));
}

void Stage_3_3::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(775, 1415) - centerOffset);
}

void Stage_3_3::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(1335, 135) - centerOffset);
}

void Stage_3_3::GenerateObstacle() {
}
