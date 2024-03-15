#pragma once
#include "vec.h"

class Point
{
public:
    Point(double x, double y);
    Point(Point* point);
    Point();
    ~Point();
    double GetX();
    double GetY();

    void SetX(double x);
    void SetY(double y);
    void SetPoint(double x, double y);

    Point operator +(Point& point) const;
    Vec operator -(Point& point) const;
    Point operator +(Vec& vec) const;
    Point operator -(Vec& vec) const;

private:
    double x;
    double y;
};
