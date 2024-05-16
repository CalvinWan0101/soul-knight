#pragma once
#include "../utils/Point.h"

class Bar {
public:
    Bar(int width, int height, COLORREF borderColor, COLORREF innerColor, COLORREF backgroundColor, Point point);
    void Show(int value, int maxValue);
private:
    int width;
    int height;
    COLORREF borderColor;
    COLORREF innerColor;
    COLORREF backgroundColor;
    Point point;
};
