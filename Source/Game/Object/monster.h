#pragma once
#include "game_object.h"
#include "..\event\event.hpp"

class Monster : public game_framework::GameObject
{
public:
    Event<void , GameObject*> run;
    Monster();
    void Start() override;
    void Update() override;
};
