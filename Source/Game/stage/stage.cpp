#include "stdafx.h"
#include "stage.h"

#include "../utils/object_manager.h"
#include "../wall/wall.h"

Stage::Stage() {
    
}

Stage::~Stage() {
    
}

game_framework::CMovingBitmap* Stage::GetBackground() {
    return &background;
}

void Stage::Initialize() {
    GenerateWall();
    SetPlayerPosition();
    SetTransferGatePosition();
    GenerateObstacle();
}

void Stage::Show(Point screenPositoin) {
    background.SetTopLeft(  static_cast<int>(-screenPositoin.GetX() - static_cast<double>(background.GetWidth()) / 2),
                            static_cast<int>(-screenPositoin.GetY() - static_cast<double>(background.GetHeight()) / 2));
    background.ShowBitmap();
}

void Stage::AddWall(Point point1, Point point2) {
    ObjectManager::Instance()->AddObject(new Wall(point1 - centerOffect, point2 - centerOffect));
}



