#include "stdafx.h"
#include "Point.h"

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::Point(Point* point) {
    this->x = point->GetX();
    this->y = point->GetY();
}

Point::Point() {
    x = 0;
    y = 0;
}

Point::~Point() {
}

double Point::GetX() {
    return x;
}

double Point::GetY() {
    return y;
}

void Point::SetX(double x) {
    this->x = x;
}

void Point::SetY(double y) {
    this->y = y;
}

void Point::SetPoint(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::Distance(Point& point) {
    return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
}

Point Point::operator +(Point& point) const {
    return Point{x + point.x, y + point.y};
}

Vec Point::operator -(Point& point) const {
    return Vec{x - point.x, y - point.y};
}

Point Point::operator +(Vec& vec) const {
    return Point{x + vec.GetX(), y + vec.GetY()};
}

Point Point::operator -(Vec& vec) const {
    return Point{x - vec.GetX(), y - vec.GetY()};
}
