#pragma once
#include "point.h"

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();
    virtual void Start();
    virtual void Update();
    void Show();
    double GetX();
    double GetY();
protected:
    Point point;
    Vec velocity;
};
