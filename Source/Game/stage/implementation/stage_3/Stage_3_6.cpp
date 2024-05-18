#include "stdafx.h"
#include "Stage_3_6.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_3_6::Stage_3_6() {
    background.LoadBitmapByString({"resources/map/3-6.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);
}

void Stage_3_6::GenerateWall() {
}

void Stage_3_6::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point() - centerOffset);
}

void Stage_3_6::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point() - centerOffset);
}

void Stage_3_6::GenerateObstacle() {
}
