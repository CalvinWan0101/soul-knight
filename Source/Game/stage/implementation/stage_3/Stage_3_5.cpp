#include "stdafx.h"
#include "Stage_3_5.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_3_5::Stage_3_5() {
    background.LoadBitmapByString({"resources/map/3-5.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    Room* room1 = new Room(Point(1312, 112), centerOffset, RoomSize::SMALL_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room2 = new Room(Point(1840, 80), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room3 = new Room(Point(0, 640), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room4 = new Room(Point(592, 592), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room5 = new Room(Point(1280, 640), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room6 = new Room(Point(1872, 672), centerOffset, RoomSize::SMALL_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room7 = new Room(Point(1792, 1200), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}}, true);

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);
    rooms.push_back(room6);
    rooms.push_back(room7);
}

void Stage_3_5::GenerateWall() {
    AddWall(Point(639, 1), Point(655, 272));
    AddWall(Point(639, 1), Point(911, 15));
    AddWall(Point(895, 1), Point(911, 271));
    AddWall(Point(591, 256), Point(735, 607));
    AddWall(Point(815, 257), Point(959, 607));
    AddWall(Point(255, 592), Point(607, 734));
    AddWall(Point(255, 815), Point(607, 959));
    AddWall(Point(1, 640), Point(272, 655));
    AddWall(Point(1, 640), Point(15, 912));
    AddWall(Point(1, 896), Point(272, 912));
    AddWall(Point(591, 944), Point(959, 960));
    AddWall(Point(943, 592), Point(1296, 736));
    AddWall(Point(943, 816), Point(1295, 960));
    AddWall(Point(1280, 896), Point(1552, 912));
    AddWall(Point(1279, 304), Point(1375, 656));
    AddWall(Point(1455, 304), Point(1551, 655));
    AddWall(Point(1311, 111), Point(1327, 319));
    AddWall(Point(1311, 111), Point(1519, 126));
    AddWall(Point(1503, 79), Point(1855, 175));
    AddWall(Point(1503, 256), Point(1855, 352));
    AddWall(Point(1840, 79), Point(2112, 94));
    AddWall(Point(2095, 80), Point(2111, 352));
    AddWall(Point(1839, 335), Point(1935, 687));
    AddWall(Point(2015, 336), Point(2112, 686));
    AddWall(Point(2064, 671), Point(2080, 879));
    AddWall(Point(1535, 640), Point(1886, 734));
    AddWall(Point(1536, 816), Point(1887, 912));
    AddWall(Point(1792, 864), Point(1937, 1214));
    AddWall(Point(2016, 864), Point(2160, 1214));
    AddWall(Point(1791, 1199), Point(1807, 1568));
    AddWall(Point(1790, 1552), Point(2160, 1567));
    AddWall(Point(2143, 1199), Point(2160, 1568));
}

void Stage_3_5::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(775, 135) - centerOffset);
}

void Stage_3_5::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(3000, 3000) - centerOffset);
}

void Stage_3_5::GenerateObstacle() {
}
