#include "stdafx.h"
#include "Stage_2_4.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../../room/RoomSize.h"

Stage_2_4::Stage_2_4() {
    background.LoadBitmapByString({"resources/map/2-4.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    MonsterRoom* room2 = new MonsterRoom(Point(640, 528), centerOffset, RoomSize::MEDIUM_SIZE, 4, 2);
    MonsterRoom* room3 = new MonsterRoom(Point(592, 1120), centerOffset, RoomSize::LARGE_SIZE, 4, 2);
    MonsterRoom* room4 = new MonsterRoom(Point(1280, 1168), centerOffset, RoomSize::MEDIUM_SIZE, 4, 2);
    MonsterRoom* room5 = new MonsterRoom(Point(640, 1808), centerOffset, RoomSize::MEDIUM_SIZE, 4, 2);

    monsterRooms.push_back(room2);
    monsterRooms.push_back(room3);
    monsterRooms.push_back(room4);
    monsterRooms.push_back(room5);

    treasureRoom = new TreasureRoom(Point(672, 0), centerOffset);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(47, 1199) - centerOffset);
    }
}

void Stage_2_4::GenerateWall() {
    AddWall(Point(671, 1), Point(687, 208));
    AddWall(Point(671, 1), Point(879, 15));
    AddWall(Point(863, 1), Point(879, 208));
    AddWall(Point(640, 192), Point(736, 543));
    AddWall(Point(816, 192), Point(912, 543));
    AddWall(Point(896, 527), Point(912, 799));
    AddWall(Point(304, 528), Point(655, 622));
    AddWall(Point(304, 703), Point(656, 800));
    AddWall(Point(113, 559), Point(320, 575));
    AddWall(Point(112, 560), Point(127, 767));
    AddWall(Point(113, 751), Point(320, 768));
    AddWall(Point(592, 784), Point(735, 1135));
    AddWall(Point(815, 784), Point(960, 1135));
    AddWall(Point(943, 1119), Point(1294, 1262));
    AddWall(Point(944, 1343), Point(1296, 1487));
    AddWall(Point(1280, 1167), Point(1552, 1182));
    AddWall(Point(1280, 1423), Point(1552, 1440));
    AddWall(Point(1536, 1168), Point(1551, 1440));
    AddWall(Point(1, 1168), Point(272, 1184));
    AddWall(Point(1, 1169), Point(15, 1440));
    AddWall(Point(1, 1423), Point(272, 1439));
    AddWall(Point(256, 1343), Point(607, 1488));
    AddWall(Point(256, 1119), Point(607, 1263));
    AddWall(Point(592, 1473), Point(736, 1823));
    AddWall(Point(816, 1472), Point(959, 1822));
    AddWall(Point(639, 1808), Point(656, 2080));
    AddWall(Point(895, 1807), Point(912, 2078));
    AddWall(Point(639, 2063), Point(913, 2078));
}

void Stage_2_4::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(135, 1303) - centerOffset);
}

void Stage_2_4::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(216, 663) - centerOffset);
}

void Stage_2_4::GenerateObstacle() {
}
