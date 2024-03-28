#pragma once
#include "../character.h"

class Monster : public Character
{
public:
    Monster();
    void Start() override;
    void Update() override;

    void SetWeapon(Weapon* weapon);
};
