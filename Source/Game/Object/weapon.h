#pragma once
#include "game_object.h"

class Weapon : game_framework::GameObject
{
public:
    Weapon();
    void Start() override;
    void Update() override;
};
