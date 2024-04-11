#pragma once
#include "../utils/invisible_object.h"

class InvisibleWall : public InvisibleObject{
public:
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
};
