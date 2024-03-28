#include "stdafx.h"
#include "hit_box.h"
#include <cmath>

HitBox::HitBox(Point& authorPoint) : authorPoint(authorPoint) {
    halfWidth = 0;
    halfHeight = 0;
}

void HitBox::SetWidth(double width) {
    this->halfWidth = width / 2;
}

void HitBox::SetHeight(double height) {
    this->halfHeight = height / 2;
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
        return true;
    }
    else {
        return false;
    }
}
