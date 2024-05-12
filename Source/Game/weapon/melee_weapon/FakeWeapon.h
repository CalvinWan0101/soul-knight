#pragma once
#include "../Weapon.h"

class FakeWeapon : public Weapon {
public:
    void Start() override;
    void Update() override;
    void LoadResources() override; 
    void Attack() override;
    void Show(Point screenPositoin) override;
    void Aim(Vec* direction) override;
    Weapon* Copy() override;
};
