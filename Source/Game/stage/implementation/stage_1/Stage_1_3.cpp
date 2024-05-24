#include "stdafx.h"
#include "Stage_1_3.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_1_3::Stage_1_3() {
    background.LoadBitmapByString({"resources/map/1-3.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    Room* room1 = new Room(Point(592, 0), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room2 = new Room(Point(640, 688), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room3 = new Room(Point(0, 1328), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room4 = new Room(Point(592, 1280), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room5 = new Room(Point(672, 1968), centerOffset, RoomSize::SMALL_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(1327, 1359) - centerOffset);
    }
}

void Stage_1_3::GenerateWall() {
    AddWall(Point(592, 0), Point(959, 15));
    AddWall(Point(592, 0), Point(607, 367));
    AddWall(Point(944, 0), Point(959, 367));
    AddWall(Point(592, 352), Point(735, 703));
    AddWall(Point(959, 352), Point(816, 703));
    AddWall(Point(640, 688), Point(655, 959));
    AddWall(Point(896, 688), Point(1247, 783));
    AddWall(Point(896, 959), Point(1247, 864));
    AddWall(Point(1232, 720), Point(1439, 735));
    AddWall(Point(1424, 720), Point(1439, 927));
    AddWall(Point(1232, 912), Point(1439, 927));
    AddWall(Point(592, 1295), Point(735, 944));
    AddWall(Point(816, 944), Point(959, 1295));
    AddWall(Point(256, 1423), Point(607, 1280));
    AddWall(Point(256, 1504), Point(607, 1647));
    AddWall(Point(0, 1328), Point(271, 1343));
    AddWall(Point(0, 1328), Point(15, 1599));
    AddWall(Point(0, 1584), Point(271, 1599));
    AddWall(Point(944, 1280), Point(1295, 1423));
    AddWall(Point(944, 1647), Point(1295, 1504));
    AddWall(Point(1280, 1328), Point(1551, 1343));
    AddWall(Point(1536, 1328), Point(1551, 1599));
    AddWall(Point(1280, 1584), Point(1551, 1599));
    AddWall(Point(592, 1632), Point(735, 1983));
    AddWall(Point(816, 1983), Point(959, 1632));
    AddWall(Point(672, 1968), Point(687, 2175));
    AddWall(Point(672, 2160), Point(879, 2175));
    AddWall(Point(864, 1968), Point(879, 2175));
}

void Stage_1_3::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(1415, 1463) - centerOffset);
}

void Stage_1_3::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(1335, 823) - centerOffset);
}

void Stage_1_3::GenerateObstacle() {
}
