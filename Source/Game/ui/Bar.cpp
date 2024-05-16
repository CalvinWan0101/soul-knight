#include "stdafx.h"
#include "Bar.h"

#include "../utils/draw/Draw.h"

Bar::Bar(int width, int height, COLORREF borderColor, COLORREF innerColor, Point point) {
    this->width = width;
    this->height = height;
    this->borderColor = borderColor;
    this->innerColor = innerColor;
    this->point = point;
}

void Bar::Show(int value, int maxValue) {
    game_framework::Draw::Instance()->EmptyRectangle(point, point + Point(width, height), borderColor,Point(5,5), 3);
    game_framework::Draw::Instance()->Rectangle(point + Point(2, 1), point + Point(width * (static_cast<double>(value) / (static_cast<double>(maxValue))), height) + Point(-1, -1), innerColor);
}


