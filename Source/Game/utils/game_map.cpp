#include "stdafx.h"
#include "game_map.h"


void GameMap::Start() {
    this->AddAnimation({
                           "resources/map/1-1.bmp",
                           "resources/map/1-2.bmp",
                           "resources/map/1-3.bmp",
                           "resources/map/1-4.bmp",
                           "resources/map/1-5.bmp",
                           "resources/map/2-1.bmp",
                           "resources/map/2-2.bmp",
                           "resources/map/2-3.bmp",
                           "resources/map/2-4.bmp",
                           "resources/map/2-5.bmp",
                           "resources/map/3-1.bmp",
                           "resources/map/3-2.bmp",
                           "resources/map/3-3.bmp",
                           "resources/map/3-4.bmp",
                           "resources/map/3-5.bmp",
                           "resources/map/3-6.bmp"
                       }, RGB(255, 255, 255), 100, true);
    SetMap(5);
    GameObject::Start();
}

void GameMap::Update() {
    GameObject::Update();
}

void GameMap::SetMap(int level, int stage) {
    cMovingBitmaps[0].SetFrameIndexOfBitmap((level - 1) * 5 + stage - 1);
}

void GameMap::SetMap(int index) {
    cMovingBitmaps[0].SetFrameIndexOfBitmap(index);
}
