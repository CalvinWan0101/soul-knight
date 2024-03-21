#include "stdafx.h"
#include "vec.h"
#include "../config.h"

#include <cmath>
#include <complex>
#include <valarray>

Vec::Vec(double x, double y) {
    this->x = x;
    this->y = y;
}

Vec::Vec(Vec* vec, double val) {
    double length = vec->GetLength();
    if (length != 0.0) {
        double ratio = val / length;
        x = vec->x * ratio;
        y = vec->y * ratio;
    }
}

Vec::Vec(Vec* vec) {
    x = vec->x;
    y = vec->y;
}

Vec::Vec() {
    x = 0;
    y = 0;
}

Vec::~Vec() {
}

double Vec::GetX() {
    return x;
}

double Vec::GetY() {
    return y;
}

double Vec::GetLength() {
    return sqrt(x * x + y * y);
}

double Vec::GetRadian() {
    double length = GetLength();
    if (length == 0.0) {
        return 0.0;
    }
    else {
        return (x < 0 ? std::acos(y / length) : std::acos(-y / length) + PI);
    }
}

double Vec::Angle(Vec* vec) {
    return vec->GetRadian() - this->GetRadian();
}

void Vec::Rotate(double radian) {
    double cosRadian = cos(radian);
    double sinRadian = sin(radian);
    double newX = x * cosRadian - y * sinRadian;
    double newY = x * sinRadian + y * cosRadian;
    x = newX;
    y = newY;
}


void Vec::SetX(double x) {
    this->x = x;
}

void Vec::SetY(double y) {
    this->y = y;
}

void Vec::SetVec(double x, double y) {
    this->x = x;
    this->y = y;
}

void Vec::SetVec(Vec* vec, double val) {
    double ratio = val / vec->GetLength();
    x = vec->x * ratio;
    y = vec->y * ratio;
}

void Vec::SetVec(Vec* vec) {
    x = vec->x;
    y = vec->y;
}

void Vec::SetLength(double length) {
    double selfLength = this->GetLength();
    if (selfLength != 0.0) {
        double ratio = length / selfLength;
        x = this->x * ratio;
        y = this->y * ratio;
    }
}

Vec Vec::operator+(Vec& vec) const {
    return Vec{x + vec.x, y + vec.y};
}

Vec Vec::operator -(Vec& vec) const {
    return Vec{x - vec.x, y - vec.y};
}
