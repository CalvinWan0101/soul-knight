#pragma once
#include "../character.h"

class Monster : public Character
{
public:
    Monster();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;

    void SetWeapon(Weapon* weapon);
};
