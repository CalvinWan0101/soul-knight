#include "stdafx.h"
#include "hit_box.h"

HitBox::HitBox(Point& authorPoint) : authorPoint(authorPoint) {
    halfWidth = 0;
    halfHeight = 0;
}

void HitBox::SetWidth(int width) {
    this->halfWidth = width / 2;
}

void HitBox::SetHeight(int height) {
    this->halfHeight = height / 2;
}

bool HitBox::IsCollision(HitBox* otherHitBox) {
    bool XOverLap = false;
    bool YOverLap = false;
    if (this->authorPoint.GetX() - otherHitBox->authorPoint.GetX() < this->halfWidth + otherHitBox->halfWidth ||
        otherHitBox->authorPoint.GetX() - this->authorPoint.GetX() < this->halfWidth + otherHitBox->halfWidth) {
        XOverLap = true;
    }
    if (this->authorPoint.GetY() - otherHitBox->authorPoint.GetY() < this->halfHeight + otherHitBox->halfHeight ||
        otherHitBox->authorPoint.GetY() - this->authorPoint.GetY() < this->halfHeight + otherHitBox->halfHeight) {
        YOverLap = true;
    }
    if (XOverLap && YOverLap) {
        return true;
    }
    else {
        return false;
    }
}
