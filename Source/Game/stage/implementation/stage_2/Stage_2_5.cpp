#include "stdafx.h"
#include "Stage_2_5.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_2_5::Stage_2_5() {
    background.LoadBitmapByString({"resources/map/2-5.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    MonsterRoom* room1 = new MonsterRoom(Point(688, 48), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room2 = new MonsterRoom(Point(1280, 0), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}}, true);
    MonsterRoom* room3 = new MonsterRoom(Point(0, 592), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room4 = new MonsterRoom(Point(688, 640), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room5 = new MonsterRoom(Point(48, 1280), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room6 = new MonsterRoom(Point(640, 1232), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    MonsterRoom* room7 = new MonsterRoom(Point(720, 1920), centerOffset, RoomSize::SMALL_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);
    rooms.push_back(room6);
    rooms.push_back(room7);

    if (vendingMachine) {
        vendingMachine->SetPosition(Point(1375, 1311) - centerOffset);
    }
}

void Stage_2_5::GenerateWall() {
    AddWall(Point(1279, 1), Point(1648, 14));
    AddWall(Point(1280, 352), Point(1648, 368));
    AddWall(Point(1632, 1), Point(1647, 367));
    AddWall(Point(944, 1), Point(1296, 143));
    AddWall(Point(944, 224), Point(1294, 368));
    AddWall(Point(688, 48), Point(960, 63));
    AddWall(Point(688, 48), Point(704, 320));
    AddWall(Point(688, 304), Point(783, 655));
    AddWall(Point(864, 304), Point(960, 655));
    AddWall(Point(944, 640), Point(960, 912));
    AddWall(Point(352, 591), Point(703, 734));
    AddWall(Point(352, 816), Point(702, 960));
    AddWall(Point(1, 591), Point(368, 606));
    AddWall(Point(1, 593), Point(15, 961));
    AddWall(Point(1, 944), Point(143, 1295));
    AddWall(Point(224, 944), Point(368, 1295));
    AddWall(Point(640, 896), Point(783, 1246));
    AddWall(Point(864, 896), Point(1008, 1248));
    AddWall(Point(305, 1232), Point(655, 1376));
    AddWall(Point(305, 1456), Point(655, 1600));
    AddWall(Point(992, 1233), Point(1343, 1374));
    AddWall(Point(992, 1456), Point(1343, 1600));
    AddWall(Point(1327, 1279), Point(1600, 1294));
    AddWall(Point(1584, 1281), Point(1600, 1552));
    AddWall(Point(1327, 1536), Point(1599, 1552));
    AddWall(Point(640, 1584), Point(784, 1935));
    AddWall(Point(864, 1584), Point(1008, 1935));
    AddWall(Point(719, 1919), Point(735, 2128));
    AddWall(Point(911, 1919), Point(927, 2128));
    AddWall(Point(719, 2111), Point(927, 2128));
    AddWall(Point(48, 1280), Point(64, 1552));
    AddWall(Point(48, 1536), Point(320, 1552));
}

void Stage_2_5::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(1464, 1415) - centerOffset);
}

void Stage_2_5::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(3000, 3000) - centerOffset);
}

void Stage_2_5::GenerateObstacle() {
}
