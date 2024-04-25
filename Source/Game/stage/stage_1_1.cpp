#include "stdafx.h"
#include "stage_1_1.h"
#include "../utils/object_manager.h"
#include "../wall/wall.h"
#include "../character/player/player.h"
#include <iostream>

#include "../character/monster/floor_1/goblin_giant.h"
#include "../weapon/hammer.h"

Stage_1_1::Stage_1_1() {
    background.LoadBitmapByString({"resources/map/1-1.bmp"}, RGB(255, 255, 255));
    centerOffect = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);
}

Stage_1_1::~Stage_1_1() = default;

void Stage_1_1::GenerateWall() {
    AddWall(Point(-100, -100), Point(190, 94));
    AddWall(Point(191, -100), Point(542, 143));
    AddWall(Point(-100, 273), Point(192, 412));
    AddWall(Point(192, 224), Point(544, 352));
    AddWall(Point(520, 352), Point(672, 703));
    AddWall(Point(452, 704), Point(591, 1060));
    AddWall(Point(752, 352), Point(879, 704));
    AddWall(Point(832, 705), Point(969, 1060));
    AddWall(Point(880, 224), Point(1232, 368));
    AddWall(Point(1233, 308), Point(1311, 656));
    AddWall(Point(1115, 562), Point(1232, 896));
    AddWall(Point(1120, 896), Point(1636, 1060));
    AddWall(Point(1471, 656), Point(1642, 895));
    AddWall(Point(1392, 304), Point(1535, 656));
    AddWall(Point(1472, 223), Point(1823, 303));
    AddWall(Point(1824, 272), Point(2116, 344));
    AddWall(Point(1472, -100), Point(1823, 144));
    AddWall(Point(1823, -100), Point(2116, 95));
    AddWall(Point(1233, -100), Point(1471, 64));
    AddWall(Point(880, -100), Point(1232, 144));
    AddWall(Point(-100, 95), Point(16, 272));
    AddWall(Point(592, 944), Point(831, 1060));
    AddWall(Point(543, -100), Point(879, 16));
    AddWall(Point(2000, 96), Point(2116, 271));
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

void Stage_1_1::DetectRoom1() {
    double x = ObjectManager::Instance()->GetPlayer()->GetPosition().GetX() + centerOffect.GetX();
    double y = ObjectManager::Instance()->GetPlayer()->GetPosition().GetY() + centerOffect.GetY();
    if (!isInRoom1 && !room1Cleared && x >= 528 && x <= 896 && y >= -1 && y <= 367) {
        isInRoom1 = true;
        SetRoom1();
    }
}

void Stage_1_1::DetectRoom2() {
    // 1-1 has only one room
}

void Stage_1_1::DetectRoom1Cleared() {
    if (!isInRoom1 || room1Cleared) {
        return;
    }

    for (auto monster : monsters) {
        if (!monster->IsDead()) {
            return;
        }
    }
    
    room1Cleared = true;
    for (auto door : doors) {
        door->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    doors.clear();
    for (auto monster : monsters) {
        monster->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    monsters.clear();
    GameObject* weapon = new Hammer();
    weapon->SetPosition(Point(700, 100) - centerOffect);
    ObjectManager::Instance()->AddObject(weapon);
}

void Stage_1_1::DetectRoom2Cleared() {
}

void Stage_1_1::SetRoom1() {
    Wall* wall1 = new Wall(Point(528, 143) - centerOffect, Point(544, 223) - centerOffect);
    Wall* wall2 = new Wall(Point(673, 352) - centerOffect, Point(751, 367) - centerOffect);
    Wall* wall3 = new Wall(Point(880, 145) - centerOffect, Point(896, 223) - centerOffect);
    doors.push_back(wall1);
    doors.push_back(wall2);
    doors.push_back(wall3);
    ObjectManager::Instance()->AddObject(wall1);
    ObjectManager::Instance()->AddObject(wall2);
    ObjectManager::Instance()->AddObject(wall3);

    Monster* monster1 = new GoblinGiant();
    monster1->SetPosition(Point(600, 200) - centerOffect);
    monsters.push_back(monster1);
    Monster* monster2 = new GoblinGiant();
    monster2->SetPosition(Point(700, 100) - centerOffect);
    monsters.push_back(monster2);
    ObjectManager::Instance()->AddObject(monster1);
    ObjectManager::Instance()->AddObject(monster2);
}

void Stage_1_1::SetRoom2() {
    // 1-1 has only one room
}
