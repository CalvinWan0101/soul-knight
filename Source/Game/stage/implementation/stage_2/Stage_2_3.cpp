#include "stdafx.h"
#include "Stage_2_3.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../../room/RoomSize.h"

Stage_2_3::Stage_2_3() {
    background.LoadBitmapByString({"resources/map/2-3.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    MonsterRoom* room2 = new MonsterRoom(Point(624, 480), centerOffset, RoomSize::LARGE_SIZE, 4,
                                         std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room3 = new MonsterRoom(Point(1312, 528), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                                         std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room4 = new MonsterRoom(Point(1904, 480), centerOffset, RoomSize::LARGE_SIZE, 4,
                                         std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room5 = new MonsterRoom(Point(1312, 1120), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                                         std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    monsterRooms.push_back(room2);
    monsterRooms.push_back(room3);
    monsterRooms.push_back(room4);
    monsterRooms.push_back(room5);

    treasureRoom = new TreasureRoom(Point(96, 560), centerOffset);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(1391, 31) - centerOffset);
    }
}

void Stage_2_3::GenerateWall() {
    AddWall(Point(95, 559), Point(303, 574));
    AddWall(Point(95, 559), Point(111, 767));
    AddWall(Point(95, 752), Point(303, 767));
    AddWall(Point(288, 704), Point(639, 847));
    AddWall(Point(288, 480), Point(640, 623));
    AddWall(Point(624, 479), Point(992, 495));
    AddWall(Point(624, 832), Point(767, 1182));
    AddWall(Point(847, 832), Point(992, 1182));
    AddWall(Point(672, 1167), Point(687, 1440));
    AddWall(Point(928, 1167), Point(944, 1440));
    AddWall(Point(673, 1424), Point(944, 1439));
    AddWall(Point(976, 481), Point(1328, 623));
    AddWall(Point(976, 704), Point(1327, 848));
    AddWall(Point(1312, 784), Point(1408, 1135));
    AddWall(Point(1488, 784), Point(1585, 1135));
    AddWall(Point(1312, 1119), Point(1327, 1391));
    AddWall(Point(1568, 1119), Point(1584, 1391));
    AddWall(Point(1313, 1376), Point(1584, 1392));
    AddWall(Point(1568, 704), Point(1920, 848));
    AddWall(Point(1568, 480), Point(1920, 623));
    AddWall(Point(1904, 832), Point(2271, 848));
    AddWall(Point(1904, 480), Point(2272, 495));
    AddWall(Point(2256, 481), Point(2272, 848));
    AddWall(Point(1312, 193), Point(1408, 543));
    AddWall(Point(1488, 193), Point(1583, 543));
    AddWall(Point(1343, 1), Point(1360, 208));
    AddWall(Point(1535, 1), Point(1552, 208));
    AddWall(Point(1344, 1), Point(1552, 15));
}

void Stage_2_3::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(1447, 104) - centerOffset);
}

void Stage_2_3::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(806, 1302) - centerOffset);
}

void Stage_2_3::GenerateObstacle() {
}
