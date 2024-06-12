#include "stdafx.h"
#include "Stage_2_1.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../../room/RoomSize.h"

Stage_2_1::Stage_2_1() {
    background.LoadBitmapByString({"resources/map/2-1.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    MonsterRoom* room2 = new MonsterRoom(Point(16, 576), centerOffset, RoomSize::MEDIUM_SIZE, 4, 2);
    MonsterRoom* room3 = new MonsterRoom(Point(608, 528), centerOffset, RoomSize::LARGE_SIZE, 4, 2);
    MonsterRoom* room4 = new MonsterRoom(Point(1296, 576), centerOffset, RoomSize::MEDIUM_SIZE, 4, 2);

    monsterRooms.push_back(room2);
    monsterRooms.push_back(room3);
    monsterRooms.push_back(room4);

    treasureRoom = new TreasureRoom(Point(688, 0), centerOffset);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(703, 1247) - centerOffset);
    }
}

void Stage_2_1::GenerateWall() {
    AddWall(Point(688, 1), Point(702, 208));
    AddWall(Point(687, 1), Point(895, 15));
    AddWall(Point(880, 1), Point(896, 208));
    AddWall(Point(608, 192), Point(752, 544));
    AddWall(Point(832, 192), Point(976, 544));
    AddWall(Point(272, 528), Point(623, 672));
    AddWall(Point(272, 752), Point(623, 896));
    AddWall(Point(16, 576), Point(287, 590));
    AddWall(Point(16, 576), Point(31, 848));
    AddWall(Point(17, 832), Point(288, 848));
    AddWall(Point(960, 528), Point(1311, 671));
    AddWall(Point(960, 752), Point(1311, 896));
    AddWall(Point(1296, 576), Point(1568, 591));
    AddWall(Point(1296, 832), Point(1568, 848));
    AddWall(Point(1552, 576), Point(1904, 672));
    AddWall(Point(1552, 752), Point(1904, 848));
    AddWall(Point(1887, 608), Point(2096, 623));
    AddWall(Point(2081, 608), Point(2096, 816));
    AddWall(Point(1888, 800), Point(2096, 816));
    AddWall(Point(608, 879), Point(751, 1231));
    AddWall(Point(831, 880), Point(976, 1232));
    AddWall(Point(655, 1216), Point(671, 1488));
    AddWall(Point(655, 1472), Point(927, 1487));
    AddWall(Point(912, 1216), Point(928, 1487));
}

void Stage_2_1::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(791, 1350) - centerOffset);
}

void Stage_2_1::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(1991, 711) - centerOffset);
}

void Stage_2_1::GenerateObstacle() {
}
