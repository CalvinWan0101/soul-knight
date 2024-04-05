#pragma once
#include "game_object.h"

class GameMap : public game_framework::GameObject {
public:
    void Start() override;
    void Update() override;
    void SetMap(int level, int stage);
    void SetMap(int index);
};
