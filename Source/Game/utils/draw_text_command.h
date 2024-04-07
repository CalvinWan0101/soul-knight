#pragma once
#include "draw_command.h"
#include "point.h"

#include <string>

class DrawTextCommand : public DrawCommand{
public:
    DrawTextCommand(Point point, int size, COLORREF color, std::string str, std::string fontName);
    ~DrawTextCommand() override;
    void Execute(CDC* cdc) override;
private:
    Point point;
    int size;
    COLORREF color;
    std::string str;
    std::string fontName;
};
