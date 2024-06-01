#include "stdafx.h"
#include "UIManager.h"

#include "../config.h"
#include "../utils/draw/Draw.h"

UIManager::UIManager() :
playerState(Point(10, 10)),
stageText(Point(850, 0)),
coinText(Point(790, 0)),
skillCDBar(Point(SIZE_X - 200 , SIZE_Y - 100)) {
}

void UIManager::Start() {
    coinText.Start();
}


void UIManager::Show() {
    playerState.Show();
    stageText.Show();
    coinText.Show();
    skillCDBar.Show();
}


