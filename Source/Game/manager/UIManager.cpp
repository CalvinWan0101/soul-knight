#include "stdafx.h"
#include "UIManager.h"

#include "../utils/draw/Draw.h"

UIManager::UIManager() : playerState(Point(10, 10)), stageText(Point(850, 0)) {
}

void UIManager::Show() {
    playerState.Show();
    stageText.Show();
}


