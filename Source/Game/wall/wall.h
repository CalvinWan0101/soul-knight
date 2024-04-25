#pragma once
#include "../utils/invisible_object.h"

class Wall : public InvisibleObject{
public:
    Wall(Point point1, Point point2);
    Wall();
    void Start() override;
    void Update() override;
    void Collision(GeneralObject* generalObject) override;
};
