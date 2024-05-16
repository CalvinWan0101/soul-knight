#pragma once
#include "../utils/Point.h"

class Bar {
public:
    Bar(int width, int height, COLORREF borderColor, COLORREF innerColor, Point point);
    void Show(int value, int maxValue);
private:
    int width;
    int height;
    COLORREF borderColor;
    COLORREF innerColor;
    Point point;
};
