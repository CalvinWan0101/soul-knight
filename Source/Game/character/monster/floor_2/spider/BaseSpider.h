#pragma once
#include "../../../Monster.h"

// TODO: BUG FIXING
class BaseSpider : public Monster, public Projectile{
public:
    BaseSpider(double level);
    void Start() override;
    void Update() override;
    void InitializeWeapon() override;
    void AutoMation() override;
    void OnDead() override;
};
