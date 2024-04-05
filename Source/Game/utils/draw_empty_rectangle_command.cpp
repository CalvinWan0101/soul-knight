#include "stdafx.h"
#include "draw_empty_rectangle_command.h"

DrawEmptyRectangleCommand::DrawEmptyRectangleCommand(Point point1, Point point2, COLORREF color, Point radius, int thickness) {
    this->point1 = point1;
    this->point2 = point2;
    this->color =  color;
    this->radius = radius;
    this->thickness = thickness;
}

DrawEmptyRectangleCommand::~DrawEmptyRectangleCommand() = default;

void DrawEmptyRectangleCommand::Execute(CDC* cdc) {
    CPen *oldPen, pen(PS_SOLID, thickness, color); 
    oldPen = cdc->SelectObject(&pen);
        
    cdc->SelectStockObject(NULL_BRUSH);
    
    cdc->RoundRect(
        static_cast<int>(point1.GetX()),
        static_cast<int>(point1.GetY()),
        static_cast<int>(point2.GetX()),
        static_cast<int>(point2.GetY()),
        static_cast<int>(radius.GetX()),
        static_cast<int>(radius.GetY())
        );
        
    cdc->SelectObject(oldPen);
    cdc->SelectStockObject(WHITE_BRUSH);
}


