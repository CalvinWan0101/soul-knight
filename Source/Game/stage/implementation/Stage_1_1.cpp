#include "stdafx.h"
#include "Stage_1_1.h"
#include "../../manager/ObjectManager.h"
#include "../../character/Player.h"
#include <iostream>

#include "../RoomSize.h"
#include "../../character/MonsterFactory.h"
#include "../../weapon/melee_weapon/Hammer.h"

Stage_1_1::Stage_1_1() {
    background.LoadBitmapByString({"resources/map/1-1.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    // room 1
    rooms.push_back(new Room(Point(528, 0), centerOffset, RoomSize::LARGE_SIZE,
                             std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 5}, {MonsterType::NORMAL_BOAR, 5}}));

    // room 2
    rooms.push_back(new Room(Point(1216, 48), centerOffset, RoomSize::MEDIUM_SIZE,
                             std::map<MonsterType, int>{{MonsterType::ELITE_GOBLIN_GUARD_SHOTGUN, 2}}));

    // room 3
    rooms.push_back(new Room(Point(1808, 80), centerOffset, RoomSize::SMALL_SIZE,
                             std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}, {MonsterType::NORMAL_BOAR, 1}}));

    // room 4
    rooms.push_back(new Room(Point(576, 688), centerOffset, RoomSize::MEDIUM_SIZE,
                             std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 10}}));
}

Stage_1_1::~Stage_1_1() = default;

void Stage_1_1::GenerateWall() {
    AddWall(Point(192, 0), Point(543, 143));
    AddWall(Point(192, 224), Point(543, 367));
    AddWall(Point(0, 80), Point(207, 95));
    AddWall(Point(0, 80), Point(15, 287));
    AddWall(Point(0, 272), Point(207, 287));
    AddWall(Point(528, 352), Point(671, 703));
    AddWall(Point(895, 352), Point(752, 703));
    AddWall(Point(576, 688), Point(591, 959));
    AddWall(Point(832, 688), Point(847, 959));
    AddWall(Point(576, 944), Point(847, 959));
    AddWall(Point(528, 0), Point(895, 15));

    AddWall(Point(880, 0), Point(1231, 143));
    AddWall(Point(880, 367), Point(1231, 224));
    AddWall(Point(1216, 304), Point(1311, 655));
    AddWall(Point(1392, 304), Point(1487, 655));
    AddWall(Point(1216, 48), Point(1487, 63));
    AddWall(Point(1216, 640), Point(1231, 911));
    AddWall(Point(1216, 896), Point(1487, 911));
    AddWall(Point(1472, 640), Point(1487, 911));
    AddWall(Point(1472, 48), Point(1823, 143));
    AddWall(Point(1823, 224), Point(1472, 319));
    AddWall(Point(1808, 80), Point(2015, 95));
    AddWall(Point(1808, 272), Point(2015, 287));
    AddWall(Point(2000, 80), Point(2015, 287));
}

void Stage_1_1::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(345, 300));
}

void Stage_1_1::SetTransferGate() {
    TransferGate* transferGate = new TransferGate();
    transferGate->SetPosition(Point(-900, -300));
    ObjectManager::Instance()->AddObject(transferGate);
}

void Stage_1_1::GenerateObstacle() {
}
