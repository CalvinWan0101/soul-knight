#include "stdafx.h"
#include "Stage_1_2.h"
#include "../../manager/ObjectManager.h"
#include "../../manager/StageManager.h"

Stage_1_2::Stage_1_2() {
    background.LoadBitmapByString({"resources/map/1-2.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);
}

void Stage_1_2::GenerateWall() {
}

void Stage_1_2::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(135, 183) - centerOffset);
}

void Stage_1_2::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(215, 823) - centerOffset);
}

void Stage_1_2::GenerateObstacle() {
}
