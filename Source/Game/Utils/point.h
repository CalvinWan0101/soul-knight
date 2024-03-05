#pragma once
#include "vec.h"

class Point
{
public:
    Point(double x, double y);
    Point(Point* point);
    ~Point();
    double GetX();
    double GetY();

    void SetX(double x);
    void SetY(double y);
    void SetPoint(double x, double y);
    
    Point operator + (Point &point) const;
    Point operator - (Point &point) const;
    Point operator + (Vec &vec) const;
    Point operator - (Vec &vec) const;
    // void Add(int, int);

private:
    double x;
    double y;
};
