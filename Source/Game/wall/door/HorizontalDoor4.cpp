#include "stdafx.h"
#include "HorizontalDoor4.h"

void HorizontalDoor4::LoadResources() {
    AddAnimation({"resources/map/door/horizontal_4.bmp"}, RGB(255, 255, 255), 0, false);
}

void HorizontalDoor4::SetTopLeft(Point leftTop) {
    SetPosition(leftTop.GetX() + 40, leftTop.GetY() + 8);
}