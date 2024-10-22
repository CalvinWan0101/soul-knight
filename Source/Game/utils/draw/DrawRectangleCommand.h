#pragma once
#include "DrawCommand.h"
#include "../Point.h"

class DrawRectangleCommand : public DrawCommand {
public:
    DrawRectangleCommand(Point point1, Point point2, COLORREF color, int alpha);
    ~DrawRectangleCommand() override;
    void Execute(CDC* cdc) override;
private:
    Point point1;
    Point point2;
    COLORREF color;
    int alpha;
};
