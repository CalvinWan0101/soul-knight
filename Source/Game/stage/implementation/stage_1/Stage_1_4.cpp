#include "stdafx.h"
#include "Stage_1_4.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../../room/RoomSize.h"

Stage_1_4::Stage_1_4() {
    background.LoadBitmapByString({"resources/map/1-4.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    MonsterRoom* room1 = new MonsterRoom(Point(640, 688), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                                         std::map<MonsterType, int>{
                                             {MonsterType::ELITE_GOBLIN_GUARD_HOE, 2},
                                             {MonsterType::ELITE_GOBLIN_GUARD_DART, 2},
                                             {MonsterType::ELITE_GOBLIN_GUARD_SHOTGUN, 2},
                                             {MonsterType::GOBLIN_SHAMAN, 1},
                                             {MonsterType::GOBLIN_GIANT, 1}
                                         });
    MonsterRoom* room3 = new MonsterRoom(Point(0, 1328), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                                         std::map<MonsterType, int>{
                                             {MonsterType::ELITE_GOBLIN_GUARD_HOE, 2},
                                             {MonsterType::ELITE_GOBLIN_GUARD_DART, 2},
                                             {MonsterType::ELITE_GOBLIN_GUARD_SHOTGUN, 2},
                                             {MonsterType::GOBLIN_SHAMAN, 1},
                                             {MonsterType::GOBLIN_GIANT, 1}
                                         });
    MonsterRoom* room4 = new MonsterRoom(Point(592, 1280), centerOffset, RoomSize::LARGE_SIZE, 4,
                                         std::map<MonsterType, int>{
                                             {MonsterType::ELITE_GOBLIN_GUARD_HOE, 2},
                                             {MonsterType::ELITE_GOBLIN_GUARD_DART, 2},
                                             {MonsterType::ELITE_GOBLIN_GUARD_SHOTGUN, 2},
                                             {MonsterType::DIRE_BOAR, 2},
                                             {MonsterType::GOBLIN_SHAMAN, 2},
                                             {MonsterType::GOBLIN_GIANT, 2}
                                         });
    MonsterRoom* room5 = new MonsterRoom(Point(640, 1968), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                                         std::map<MonsterType, int>{
                                             {MonsterType::ELITE_GOBLIN_GUARD_HOE, 2},
                                             {MonsterType::ELITE_GOBLIN_GUARD_DART, 2},
                                             {MonsterType::ELITE_GOBLIN_GUARD_SHOTGUN, 2},
                                             {MonsterType::GOBLIN_SHAMAN, 1},
                                             {MonsterType::GOBLIN_GIANT, 1}
                                         });

    monsterRooms.push_back(room1);
    monsterRooms.push_back(room3);
    monsterRooms.push_back(room4);
    monsterRooms.push_back(room5);

    treasureRoom = new TreasureRoom(Point(1232, 720), centerOffset);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(1327, 1359) - centerOffset);
    }
}

void Stage_1_4::GenerateWall() {
    AddWall(Point(640, 352), Point(736, 703));
    AddWall(Point(672, 160), Point(688, 368));
    AddWall(Point(672, 160), Point(880, 176));
    AddWall(Point(863, 160), Point(880, 368));
    AddWall(Point(816, 352), Point(912, 705));
    AddWall(Point(896, 688), Point(1248, 784));
    AddWall(Point(1231, 720), Point(1439, 736));
    AddWall(Point(1423, 720), Point(1439, 928));
    AddWall(Point(1231, 912), Point(1439, 928));
    AddWall(Point(896, 864), Point(1247, 960));
    AddWall(Point(640, 688), Point(656, 960));
    AddWall(Point(591, 944), Point(734, 1295));
    AddWall(Point(816, 944), Point(960, 1296));
    AddWall(Point(944, 1280), Point(1295, 1424));
    AddWall(Point(944, 1504), Point(1296, 1647));
    AddWall(Point(1280, 1328), Point(1552, 1343));
    AddWall(Point(1536, 1328), Point(1552, 1600));
    AddWall(Point(1279, 1584), Point(1552, 1600));
    AddWall(Point(256, 1280), Point(608, 1423));
    AddWall(Point(255, 1505), Point(606, 1648));
    AddWall(Point(1, 1328), Point(271, 1344));
    AddWall(Point(1, 1328), Point(16, 1600));
    AddWall(Point(1, 1584), Point(271, 1600));
    AddWall(Point(592, 1632), Point(735, 1983));
    AddWall(Point(815, 1632), Point(960, 1984));
    AddWall(Point(640, 1969), Point(656, 2240));
    AddWall(Point(895, 1968), Point(912, 2240));
    AddWall(Point(641, 2224), Point(912, 2240));
}

void Stage_1_4::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(1415, 1463) - centerOffset);
}

void Stage_1_4::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(775, 263) - centerOffset);
}

void Stage_1_4::GenerateObstacle() {
}
