#include "stdafx.h"
#include "VerticalDoor1.h"

void VerticalDoor1::LoadResources() {
    AddAnimation({"resources/map/door/vertical_1.bmp"}, RGB(255, 255, 255), 0, false);
}

void VerticalDoor1::SetTopLeft(Point leftTop) {
    SetPosition(leftTop.GetX() + 8, leftTop.GetY() + 40);
}
