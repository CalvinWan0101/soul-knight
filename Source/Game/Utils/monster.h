#pragma once
#include "game_object.h"

class Monster : public GameObject
{
public:
    Monster(Point point, Vec speed, std::vector<game_framework::CMovingBitmap> cMovingBitmaps);
    void Start() override;
    void Update() override;
};
