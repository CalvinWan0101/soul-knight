#pragma once
#include "../character/Player.h"
#include "Bar.h"

class PlayerState {
public:
    PlayerState();
    void Show();

protected:
    Bar HpBar;
    Bar MpBar;
    Bar ShildBar;
    Player* player;
};
