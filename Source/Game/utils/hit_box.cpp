#include "stdafx.h"
#include "hit_box.h"
#include <cmath>

#include "draw/draw.h"
#include "../config.h"

HitBox::HitBox(Point& authorPoint) : authorPoint(authorPoint) {
    halfWidth = 0;
    halfHeight = 0;
    isCollisionInThisFrame = false;
}

void HitBox::SetWidth(double width) {
    this->halfWidth = width / 2;
}

void HitBox::SetHeight(double height) {
    this->halfHeight = height / 2;
}

double HitBox::GetHalfWidth() {
    return halfWidth;
}

double HitBox::GetHalfHeight() {
    return halfHeight;
}

bool HitBox::IsCollision(HitBox* otherHitBox) {
    bool XOverLap = false;
    bool YOverLap = false;
    if (abs(this->authorPoint.GetX() - otherHitBox->authorPoint.GetX()) < this->halfWidth + otherHitBox->halfWidth) {
        XOverLap = true;
    }
    if (abs(this->authorPoint.GetY() - otherHitBox->authorPoint.GetY()) < this->halfHeight + otherHitBox->halfHeight) {
        YOverLap = true;
    }
    if (XOverLap && YOverLap) {
        isCollisionInThisFrame = true; // TODO: Test code for HitBox collision visualization
        otherHitBox->isCollisionInThisFrame = true;
        return true;
    }
    else {
        return false;
    }
}

void HitBox::Show(Point screenPositoin) {
    double screenX = this->authorPoint.GetX() - screenPositoin.GetX();
    double screenY = this->authorPoint.GetY() - screenPositoin.GetY();
    if (screenX > 0 && screenX < SIZE_X && screenY > 0 && screenY < SIZE_Y) {
        game_framework::Draw::Instance()->EmptyRectangle(
        Point(screenX - halfWidth, screenY - halfHeight),
        Point(screenX + halfWidth, screenY + halfHeight),
        (isCollisionInThisFrame ? RGB(235,16,0) : RGB(8,249,24))
        );
    }
    isCollisionInThisFrame = false;
}

