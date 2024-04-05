#pragma once
#include "point.h"

namespace game_framework {
    class Draw {
    public:
        static Draw* Instance();
        void Rectangle(Point point1, Point point2, COLORREF color, Point radius = Point(0, 0));
        void EmptyRectangle(Point point1, Point point2, COLORREF color, Point radius = Point(0, 0), int thickness = 1);
    private:
        static Draw* instance;
    };   
}
