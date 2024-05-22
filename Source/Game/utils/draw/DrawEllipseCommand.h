#pragma once
#include "DrawCommand.h"
#include "../Point.h"

class DrawEllipseCommand : public DrawCommand {
public:
    DrawEllipseCommand(Point point1, Point point2, COLORREF color, int alpha);
    ~DrawEllipseCommand() override = default;
    void Execute(CDC* cdc) override;
private:
    Point point1;
    Point point2;
    COLORREF color;
    int alpha;
};
