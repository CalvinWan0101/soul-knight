#include "stdafx.h"
#include "stage_1_1.h"
#include "../utils/object_manager.h"
#include "../wall/wall.h"

Stage_1_1::Stage_1_1() {
    background.LoadBitmapByString({"resources/map/1-1.bmp"}, RGB(255, 255, 255));
    centerOffect = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);
}

Stage_1_1::~Stage_1_1() = default;

void Stage_1_1::GenerateWall() {
    AddWall(Point(1, 1), Point(190, 94));
    AddWall(Point(191, 1), Point(542, 143));
    AddWall(Point(1, 273), Point(192, 412));
    AddWall(Point(192, 224), Point(544, 352));
    AddWall(Point(520, 352), Point(672, 703));
    AddWall(Point(452, 704), Point(591, 960));
    AddWall(Point(752, 352), Point(879, 704));
    AddWall(Point(832, 705), Point(969, 960));
    AddWall(Point(880, 224), Point(1232, 368));
    AddWall(Point(1233, 308), Point(1311, 656));
    AddWall(Point(1120, 623), Point(1232, 896));
    AddWall(Point(1120, 896), Point(1636, 960));
    AddWall(Point(1471, 656), Point(1642, 895));
    AddWall(Point(1392, 304), Point(1535, 656));
    AddWall(Point(1472, 223), Point(1823, 303));
    AddWall(Point(1824, 272), Point(2016, 344));
    AddWall(Point(1472, 22), Point(1823, 144));
    AddWall(Point(1823, 8), Point(2016, 95));
    AddWall(Point(1233, 1), Point(1471, 64));
    AddWall(Point(880, 1), Point(1232, 144));
}

void Stage_1_1::SetPlayerPosition() {
    
}

void Stage_1_1::SetTransferGatePosition() {
    
}

void Stage_1_1::GenerateObstacle() {
    
}



