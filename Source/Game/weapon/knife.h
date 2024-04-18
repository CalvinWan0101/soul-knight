#pragma once
#include "weapon.h"

class Knife : public Weapon{
public:
    Knife();
    void Start() override;
    void Update() override;
    void Attack() override = 0;
    void Collision(GameObject* gameObject) override;
};
