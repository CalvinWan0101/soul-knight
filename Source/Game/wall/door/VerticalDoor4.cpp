#include "stdafx.h"
#include "VerticalDoor4.h"

void VerticalDoor4::LoadResources() {
    AddAnimation({"resources/map/door/vertical_4.bmp"}, RGB(255, 255, 255), 0, false);
}

void VerticalDoor4::SetTopLeft(Point leftTop) {
    SetPosition(leftTop.GetX() + 8, leftTop.GetY() + 40);
}