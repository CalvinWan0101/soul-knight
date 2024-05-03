#pragma once
#include "../utils/object/InvisibleObject.h"

class Wall : public InvisibleObject{
public:
    Wall(Point point1, Point point2);
    Wall();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
};
