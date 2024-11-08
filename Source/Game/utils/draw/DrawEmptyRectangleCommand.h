#pragma once
#include "DrawCommand.h"
#include "../Point.h"

class DrawEmptyRectangleCommand : public DrawCommand{
public:
    DrawEmptyRectangleCommand(Point point1, Point point2, COLORREF color, Point radius, int thickness);
    ~DrawEmptyRectangleCommand() override;
    void Execute(CDC* cdc) override;
private:
    Point point1;
    Point point2;
    COLORREF color;
    Point radius;
    int thickness;
};
