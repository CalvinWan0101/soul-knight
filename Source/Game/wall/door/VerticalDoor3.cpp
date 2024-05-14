#include "stdafx.h"
#include "VerticalDoor3.h"

void VerticalDoor3::LoadResources() {
    AddAnimation({"resources/map/door/vertical_3.bmp"}, RGB(255, 255, 255), 0, false);
}

void VerticalDoor3::SetTopLeft(Point leftTop) {
    SetPosition(leftTop.GetX() + 8, leftTop.GetY() + 40);
}