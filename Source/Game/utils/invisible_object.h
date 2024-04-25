#pragma once
#include "general_object.h"

class InvisibleObject : public  game_framework::GeneralObject{
public:
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void Collision(GeneralObject* generalObject) override;
};
