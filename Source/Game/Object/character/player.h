#pragma once
#include "../game_object.h"
#include "character.h"

class Player : public Character
{
public:
    Player();
    virtual void Start() override;
    virtual void Update() override;
    
    int GetMP();
    int GetMaxMP();
    int GetShield();
    int GetMaxShield();
protected:
    int mp;
    int maxMp;
    int shield;
    int maxShild;
};