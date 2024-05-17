#pragma once
#include "../../Library/gameutil.h"
#include "../utils/Point.h"

class CoinText {
public:
    CoinText(Point point);
    void Start();
    void Show();

private:
    game_framework::CMovingBitmap coinIcon;
    Point point;
};
