#include "stdafx.h"
#include "Stage.h"

#include "../manager/ObjectManager.h"
#include "../wall/Wall.h"

Stage::Stage() {
}

Stage::~Stage() {
    for (auto room : rooms) {
        delete room;
    }
}

game_framework::CMovingBitmap* Stage::GetBackground() {
    return &background;
}

void Stage::Initialize() {
    GenerateWall();
    SetPlayerPosition();
    SetTransferGate();
    GenerateObstacle();
}

void Stage::SetMap(int level, int stage) {
}


void Stage::Show(Point screenPositoin) {
    background.SetTopLeft(static_cast<int>(-screenPositoin.GetX() - static_cast<double>(background.GetWidth()) / 2),
                          static_cast<int>(-screenPositoin.GetY() - static_cast<double>(background.GetHeight()) / 2));
    background.ShowBitmap();
}

void Stage::AddWall(Point point1, Point point2) {
    ObjectManager::Instance()->AddObject(new Wall(point1 - centerOffset, point2 - centerOffset));
}

void Stage::IsInsideRoom() {
    for (auto room : rooms) {
        room->IsInside();
    }
}

void Stage::IsRoomCleared() {
    for (auto room : rooms) {
        room->IsCleared();
    }
}
