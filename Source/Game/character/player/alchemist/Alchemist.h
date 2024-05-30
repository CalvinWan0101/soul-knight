#pragma once
#include "../../Player.h"

class Alchemist : public Player{
public:
    Alchemist();
    void Start() override;
    void Update() override;

    void Skill() override;

    void LoadResources() override;
};
