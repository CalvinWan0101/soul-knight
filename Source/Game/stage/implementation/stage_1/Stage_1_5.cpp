#include "stdafx.h"
#include "Stage_1_5.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_1_5::Stage_1_5() {
    background.LoadBitmapByString({"resources/map/1-5.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    Room* room1 = new Room(Point(0, 544), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}}, true);
    Room* room2 = new Room(Point(688, 592), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room3 = new Room(Point(1360, 624), centerOffset, RoomSize::SMALL_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room4 = new Room(Point(48, 1232), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room5 = new Room(Point(640, 1184), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room6 = new Room(Point(1328, 1232), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);
    rooms.push_back(room6);
}

void Stage_1_5::GenerateWall() {
    AddWall(Point(688, 1), Point(704, 272));
    AddWall(Point(688, 1), Point(960, 15));
    AddWall(Point(944, 1), Point(960, 272));
    AddWall(Point(688, 255), Point(783, 608));
    AddWall(Point(864, 256), Point(960, 608));
    AddWall(Point(688, 592), Point(704, 864));
    AddWall(Point(944, 592), Point(1375, 688));
    AddWall(Point(1360, 624), Point(1568, 640));
    AddWall(Point(1552, 624), Point(1568, 832));
    AddWall(Point(1504, 816), Point(1599, 1248));
    AddWall(Point(1328, 816), Point(1424, 1248));
    AddWall(Point(944, 768), Point(1375, 864));
    AddWall(Point(864, 848), Point(1008, 1199));
    AddWall(Point(992, 1183), Point(1343, 1327));
    AddWall(Point(639, 849), Point(785, 1200));
    AddWall(Point(1584, 1232), Point(1599, 1503));
    AddWall(Point(1329, 1488), Point(1599, 1504));
    AddWall(Point(992, 1408), Point(1344, 1552));
    AddWall(Point(304, 1184), Point(657, 1328));
    AddWall(Point(303, 1408), Point(656, 1552));
    AddWall(Point(224, 896), Point(368, 1247));
    AddWall(Point(48, 1488), Point(320, 1504));
    AddWall(Point(48, 1232), Point(64, 1504));
    AddWall(Point(1, 896), Point(144, 1247));
    AddWall(Point(1, 544), Point(16, 911));
    AddWall(Point(1, 544), Point(368, 559));
    AddWall(Point(352, 544), Point(368, 912));
    AddWall(Point(640, 1535), Point(1008, 1552));
}

void Stage_1_5::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(823, 135) - centerOffset);
}

void Stage_1_5::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(3000, 3000) - centerOffset);
}

void Stage_1_5::GenerateObstacle() {
}
