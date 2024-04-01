#pragma once
#include "point.h"

namespace game_framework {
    class Draw {
    public:
        static void Rectangle(Point point1, Point point2, COLORREF color, Point radius = Point(0, 0));
        static void EmptyRectangle(Point point1, Point point2, COLORREF color, Point radius = Point(0, 0), int thickness = 1);
    };   
}