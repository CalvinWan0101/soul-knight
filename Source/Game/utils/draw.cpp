#include "stdafx.h"

#include <ddraw.h> //necessary include
#include "../Library/gameutil.h" //necessary include
#include "../Library/gamecore.h" //necessary include
#include "draw.h"


namespace game_framework {
    void Draw::Rectangle(Point point1, Point point2, COLORREF color, Point radius) {
        CDC *cdc = CDDraw::GetBackCDC(); // get CDC
        
        CPen *oldPen, pen(PS_NULL, 0, RGB(0, 0, 0)); //
        oldPen = cdc->SelectObject(&pen);
        
        CBrush *oldBrush, brush(color); // brash
        oldBrush = cdc->SelectObject(&brush);
        cdc->SelectStockObject(WHITE_BRUSH);
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
        CDDraw::ReleaseBackCDC();
    }
    
    void Draw::EmptyRectangle(Point point1, Point point2, COLORREF color, Point radius, int thickness) {
        CDC *cdc = CDDraw::GetBackCDC(); // get CDC
        
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
        CDDraw::ReleaseBackCDC();
    }

}

