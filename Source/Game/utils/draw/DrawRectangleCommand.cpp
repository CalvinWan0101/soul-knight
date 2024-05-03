#include "stdafx.h"
#include "DrawRectangleCommand.h"

DrawRectangleCommand::DrawRectangleCommand(Point point1, Point point2, COLORREF color, Point radius) {
    this->point1 = point1;
    this->point2 = point2;
    this->color = color;
    this->radius = radius;
}

DrawRectangleCommand::~DrawRectangleCommand() = default;

void DrawRectangleCommand::Execute(CDC* cdc) {
    CPen *oldPen, pen(PS_NULL, 0, RGB(0, 0, 0)); //
    oldPen = cdc->SelectObject(&pen);
        
    CBrush *oldBrush, brush(color); // brash
    oldBrush = cdc->SelectObject(&brush);
    
    cdc->RoundRect(
        static_cast<int>(point1.GetX()),
        static_cast<int>(point1.GetY()),
        static_cast<int>(point2.GetX()),
        static_cast<int>(point2.GetY()),
        static_cast<int>(radius.GetX()),
        static_cast<int>(radius.GetY())
        );
        
    cdc->SelectObject(oldPen);
    cdc->SelectObject(oldBrush);
}

