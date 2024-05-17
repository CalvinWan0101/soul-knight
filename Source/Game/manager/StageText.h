#pragma once
#include "../utils/Point.h"

class StageText {
public:
    StageText(Point point);
    void Show();
private:
    Point point;
};
