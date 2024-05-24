#include "stdafx.h"
#include "Stage_3_6.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"

Stage_3_6::Stage_3_6() {
    background.LoadBitmapByString({"resources/map/3-6.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);
}

void Stage_3_6::GenerateWall() {
    AddWall(Point(1, 1), Point(271, 16));
    AddWall(Point(1, 1), Point(16, 272));
    AddWall(Point(1, 256), Point(272, 271));
    AddWall(Point(257, 177), Point(608, 272));
    AddWall(Point(256, 1), Point(607, 94));
    AddWall(Point(592, 224), Point(800, 240));
    AddWall(Point(592, 32), Point(800, 47));
    AddWall(Point(785, 32), Point(800, 240));
}

void Stage_3_6::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(135, 135) - centerOffset);
}

void Stage_3_6::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(695, 135) - centerOffset);
}

void Stage_3_6::GenerateObstacle() {
}
