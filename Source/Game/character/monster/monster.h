#pragma once
#include "../../utils/game_object.h"

class Monster : public game_framework::GameObject
{
public:
    Monster();
    void Start() override = 0;
    void Update() override = 0;
};
