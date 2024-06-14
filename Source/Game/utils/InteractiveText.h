#pragma once
#include <string>

#include "Point.h"

class InteractiveText {
public:
    enum Rarity {
        COMMON = RGB(255, 255, 255),   // white
        UNCOMMON = RGB(0, 200, 0),     // green
        RARE = RGB(0, 100, 255),       // blue
        EPIC = RGB(146, 38, 213),      // purple
        LEGENDARY = RGB(254, 193, 64), // orange
        MYTHIC = RGB(255, 0, 0)        // red
    };

    InteractiveText(std::string displayText, Rarity rarity = Rarity::COMMON, int verticalOffset = -25);
    void Show(Point screenPoint);
    void Interactive();

private:
    std::string displayText;
    COLORREF color;
    bool isInteractive;
    Point displayOffset;
};
