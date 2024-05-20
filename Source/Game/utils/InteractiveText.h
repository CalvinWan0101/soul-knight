#pragma once
#include <string>

#include "Point.h"

class InteractiveText {
public:
    enum Rarity {
        COMMON = RGB(255,255,255),
        UNCOMMON = RGB(0,200,0),
        RARE = RGB(0,100,255),
        EPIC = RGB(146,38,213),
        LEGENDARY = RGB(205,131,0),
        MYTHIC = RGB(255,0,0)
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
