#pragma once
#include "../MeleeWeapon.h"

class CurvedSword : public MeleeWeapon {
public:
    CurvedSword(double damage = 4, Point position = {0, 0});
    Weapon* Copy() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Attack() override;
};
