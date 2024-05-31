#pragma once
#include "Bar.h"
#include "../character/Player.h"
#include "../utils/Point.h"

class SkillCDBar {
public:
    SkillCDBar(Point point);
    void Show();
private:
    Bar skillCD;
    Player* player;
    Point point;
};
