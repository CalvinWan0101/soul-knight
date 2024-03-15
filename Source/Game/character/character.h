#pragma once
#include "../utils/game_object.h"

class Character : public game_framework::GameObject
{
public:
    Character();
    virtual void Start() override;
    virtual void Update() override;

    int GetHP();
    int GetMaxHP();

protected:
    void CheckState();
    int hp;
    int maxHp;

    enum Face
    {
        RIGHT,
        LEFT
    };

    enum State
    {
        IDLE,
        RUN,
        DEAD,
        READY
    };

    Face face;
    State state;
    Vec vision;
};
