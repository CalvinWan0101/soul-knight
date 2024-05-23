#include "stdafx.h"
#include "DrawEllipseCommand.h"

#include "../../config.h"

DrawEllipseCommand::DrawEllipseCommand(Point point1, Point point2, COLORREF color, int alpha) {
    this->point1 = point1;
    this->point2 = point2;
    this->color = color;
    this->alpha = alpha;
}

void DrawEllipseCommand::Execute(CDC* cdc) {
    if (alpha == 255 || TRANSLUCENT_EFFECT == false) {
        CPen *oldPen, pen(PS_NULL, 0, RGB(0, 0, 0)); //
        oldPen = cdc->SelectObject(&pen);
        
        CBrush *oldBrush, brush(color); // brash
        oldBrush = cdc->SelectObject(&brush);
    
        cdc->Ellipse(
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
        CRect src(rect);
        src.OffsetRect(CSize(-rect.left, -rect.top));

        CBitmap bitmap2;
        bitmap2.CreateCompatibleBitmap(cdc, rect.Width(), rect.Height());
        CBitmap* pOldBitmap2 = alphaCDC.SelectObject(&bitmap2);

        alphaCDC.FillSolidRect(src, RGB(50,50,50));
        alphaCDC.SetBkMode(TRANSPARENT);

        CBrush brush(color);
        CBrush* pOldBrush = alphaCDC.SelectObject(&brush);
        alphaCDC.Ellipse(src);
        
        BLENDFUNCTION blendFunc = {0};
        blendFunc.BlendOp = AC_SRC_OVER;
        blendFunc.BlendFlags = 0;
        blendFunc.SourceConstantAlpha = this->alpha;
        blendFunc.AlphaFormat = 0; // 0 if no per-pixel alpha

        // Use AlphaBlend with proper parameters
        ::AlphaBlend(cdc->GetSafeHdc(), rect.left, rect.top, rect.Width(),
                     rect.Height(), alphaCDC.GetSafeHdc(), 0, 0,
                     rect.Width(), rect.Height(), blendFunc);

        // TransparentBlt with proper transparency key (RGB(0, 0, 0))

        alphaCDC.SelectObject(pOldBitmap2);

        // Clean up to avoid resource leaks
        alphaCDC.DeleteDC();
    }
}

