#include "stdafx.h"
#include "StageText.h"

#include <string>

#include "../manager/StageManager.h"
#include "../utils/draw/Draw.h"

StageText::StageText(Point point) {
    this->point = point;
}

void StageText::Show() {
    std::string stageStr = std::to_string(StageManager::Instance()->GetLevelNumber()) + " - " + std::to_string(StageManager::Instance()->GetStageNumber());
    game_framework::Draw::Instance()->Text(point + Point(25, 15), 42, RGB(255, 255, 255), stageStr, "MS Gothic");
    game_framework::Draw::Instance()->Rectangle(point, point + Point(164, 70), RGB(0, 0, 0), 100);
}


