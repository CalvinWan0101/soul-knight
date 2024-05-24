#pragma once
#include "KinghtSkillEffect.h"
#include "../../Player.h"

class Knight : public Player {
public:
    Knight();
    void Start() override;
    void Update() override;

    void Attack() override;
    
    void Skill() override;
    
    void LoadResources() override;
private:
    int skillKeepCounter;
    int skillKeepMaxFrame;
    KinghtSkillEffect* skillEffect;
};
