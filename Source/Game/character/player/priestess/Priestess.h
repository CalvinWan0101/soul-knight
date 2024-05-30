#pragma once
#include "../../Player.h"

class Priestess : public Player{
public:
    Priestess();
    void Start() override;
    void Update() override;;
    
    void Skill() override;

    void LoadResources() override;
};
