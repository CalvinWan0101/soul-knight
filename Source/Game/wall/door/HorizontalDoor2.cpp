#include "stdafx.h"
#include "HorizontalDoor2.h"

void HorizontalDoor2::LoadResources() {
    AddAnimation({"resources/map/door/horizontal_2.bmp"}, RGB(255, 255, 255), 0, false);
}

void HorizontalDoor2::SetTopLeft(Point leftTop) {
    SetPosition(leftTop.GetX() + 40, leftTop.GetY() + 8);
}
