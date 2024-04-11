#pragma once
#include "game_object.h"

class InvisibleObject : public  game_framework::GameObject{
public:
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void Collision(GameObject* gameObject) override;
};
