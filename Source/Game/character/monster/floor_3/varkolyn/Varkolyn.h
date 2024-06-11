#pragma once
#include "../../../Monster.h"

class Varkolyn : public Monster, public Projectile {
public:
    Varkolyn(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void InitializeWeapon() override;
    void AutoMation() override;
    void OnDead() override;
};
