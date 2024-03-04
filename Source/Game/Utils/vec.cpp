#include "stdafx.h"
#include "vec.h"

#include <cmath>

Vec::Vec(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vec::Vec(Vec* vec, double val)
{
    double ratio = val / vec->GetLength();
    x = vec->GetX() * ratio;
    y = vec->GetY() * ratio;
}

Vec::Vec(Vec* vec)
{
    x = vec->GetX();
    y = vec->GetY();
}

Vec::~Vec()
{
    
}

double Vec::GetX()
{
    return x;
}

double Vec::GetY()
{
    return y;
}

double Vec::GetLength()
{
    return sqrt(x * x + y * y);
}

void Vec::SetX(double x)
{
    this->x = x;
}

void Vec::SetY(double y)
{
    this->y = y;
}

void Vec::SetVec(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Vec::SetVec(Vec* vec, double val)
{
    double ratio = val / vec->GetLength();
    x = vec->GetX() * ratio;
    y = vec->GetY() * ratio;
}

void Vec::SetVec(Vec* vec)
{
    x = vec->GetX();
    y = vec->GetY();
}

void Vec::SetLength(double length)
{
    double ratio = length / this->GetLength();
    x = x * ratio;
    y = y * ratio;
}

Vec Vec::operator+(Vec& vec) const
{
    return Vec(x + vec.GetX() , y + vec.GetY());
}

Vec Vec::operator - (Vec& vec) const
{
    return Vec(x - vec.GetX() , y - vec.GetY());
}
