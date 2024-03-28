#include "stdafx.h"
#include "game_map.h"


void GameMap::Start() {
    this->AddAnimation({
                           "resources/map.bmp",
                       }, RGB(255, 255, 255), 100, true);
    GameObject::Start();
}

void GameMap::Update() {
    GameObject::Update();
}
