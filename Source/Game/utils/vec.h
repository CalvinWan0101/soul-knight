#pragma once

class Vec {
public:
    Vec(double x, double y);
    Vec(Vec* vec, double val);
    Vec(Vec* vec);
    Vec();
    ~Vec();
    double GetX();
    double GetY();
    double GetLength();
    double GetRadian();
    double Angle(Vec* vec);
    void Rotate(double radian);
    void SetX(double x);
    void SetY(double y);
    void SetVec(double x, double y);
    void SetVec(Vec* vec, double val);
    void SetVec(Vec* vec);
    void SetLength(double length);
    Vec operator +(Vec& vec) const;
    Vec operator -(Vec& vec) const;

private:
    double x;
    double y;
};
