#pragma once
#include "../../utils/game_object.h"
#include "../../character/character.h"

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

    void SetVision(Vec vision);

protected:
    int mp;
    int maxMp;
    int shield;
    int maxShild;
};
