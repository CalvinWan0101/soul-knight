#include "stdafx.h"
#include "HorizontalDoor3.h"

void HorizontalDoor3::LoadResources() {
    AddAnimation({"resources/map/door/horizontal_3.bmp"}, RGB(255, 255, 255), 0, false);
}

void HorizontalDoor3::SetTopLeft(Point leftTop) {
    SetPosition(leftTop.GetX() + 40, leftTop.GetY() + 8);
}