#pragma once
#include "../../utils/game_object.h"
#include "../../utils/event.hpp"

class Monster : public game_framework::GameObject
{
public:
    Event<void, GameObject*> run;
    Monster();
    void Start() override;
    void Update() override;
};
