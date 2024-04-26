#pragma once
#include "general_object.h"

class InvisibleObject : public  GeneralObject{
public:
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void Collision(GameObject* gameObject) override;
};
