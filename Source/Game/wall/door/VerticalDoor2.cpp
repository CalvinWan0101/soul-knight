#include "stdafx.h"
#include "VerticalDoor2.h"

void VerticalDoor2::LoadResources() {
    AddAnimation({"resources/map/door/vertical_2.bmp"}, RGB(255, 255, 255), 0, false);
}

void VerticalDoor2::SetTopLeft(Point leftTop) {
    SetPosition(leftTop.GetX() + 8, leftTop.GetY() + 40);
}