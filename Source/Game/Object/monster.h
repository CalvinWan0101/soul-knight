#pragma once
#include "game_object.h"

class Monster : public game_framework::GameObject
{
public:
    Monster();
    void Start() override;
    void Update() override;
};
