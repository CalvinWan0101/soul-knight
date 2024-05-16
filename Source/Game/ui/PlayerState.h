#pragma once
#include "../character/Player.h"
#include "Bar.h"

class PlayerState {
public:
    PlayerState(Point point);
    void Show();

private:
    Bar HpBar;
    Bar MpBar;
    Bar ShildBar;
    Player* player;
    Point point;
};
