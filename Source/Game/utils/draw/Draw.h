#pragma once
#include "DrawCommand.h"
#include "../Point.h"

#include <vector>
#include <string>

namespace game_framework {
    class Draw {
    public:
        static Draw* Instance();
        void Rectangle(Point point1, Point point2, COLORREF color, Point radius = Point(0, 0));
        void EmptyRectangle(Point point1, Point point2, COLORREF color, Point radius = Point(0, 0), int thickness = 1);
        void Text(Point point, int size, COLORREF color, std::string str, std::string fontName = "Arial");
        void Show();
        void SwitchIsDisplay();
    private:
        static Draw* instance;
        std::vector<DrawCommand*> drawCommands;
        bool isDisplayed;
    };
}
