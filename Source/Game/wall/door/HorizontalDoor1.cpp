#include "stdafx.h"
#include "HorizontalDoor1.h"

void HorizontalDoor1::LoadResources() {
    AddAnimation({"resources/map/door/horizontal_1.bmp"}, RGB(255, 255, 255), 0, false);
}

void HorizontalDoor1::SetTopLeft(Point leftTop) {
    SetPosition(leftTop.GetX() + 40, leftTop.GetY() + 8);
}
