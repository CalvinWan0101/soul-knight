#include "stdafx.h"
#include "DrawRectangleCommand.h"

#include "../../config.h"

DrawRectangleCommand::DrawRectangleCommand(Point point1, Point point2, COLORREF color, int alpha) {
    this->point1 = point1;
    this->point2 = point2;
    this->color = color;
    this->alpha = alpha;
}

DrawRectangleCommand::~DrawRectangleCommand() = default;

void DrawRectangleCommand::Execute(CDC* cdc) {
    if (alpha == 255 || TRANSLUCENT_EFFECT == false ) {
        CPen *oldPen, pen(PS_NULL, 0, RGB(0, 0, 0)); //
        oldPen = cdc->SelectObject(&pen);
        
        CBrush *oldBrush, brush(color); // brash
        oldBrush = cdc->SelectObject(&brush);
    
        cdc->Rectangle(
            static_cast<int>(point1.GetX()),
            static_cast<int>(point1.GetY()),
            static_cast<int>(point2.GetX()),
            static_cast<int>(point2.GetY())
            );
        
        cdc->SelectObject(oldPen);
        cdc->SelectObject(oldBrush);
    }
    else {
        CDC alphaCDC;
        alphaCDC.CreateCompatibleDC(cdc);
        CRect rect(static_cast<int>(point1.GetX()), static_cast<int>(point1.GetY()), static_cast<int>(point2.GetX()), static_cast<int>(point2.GetY()));

        CBitmap bitmap, *pOldBitmap;
        bitmap.CreateCompatibleBitmap(cdc, rect.right, rect.bottom);
        CRect src(rect);
        src.OffsetRect(CSize(-rect.left, -rect.top));
        pOldBitmap = alphaCDC.SelectObject(&bitmap);
        alphaCDC.FillSolidRect(src, color); 

        BLENDFUNCTION blendFunc = {0};
        blendFunc.SourceConstantAlpha = this->alpha;
        blendFunc.BlendOp             = AC_SRC_OVER;

        ::AlphaBlend(cdc->GetSafeHdc(), rect.left, rect.top, rect.right - rect.left,
                        rect.bottom - rect.top, alphaCDC.GetSafeHdc(), src.left, src.top, src.right - src.left,
                        src.bottom - src.top, blendFunc);

        alphaCDC.SelectObject(pOldBitmap);
    }
}

