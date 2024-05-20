#pragma once
#include "../utils/object/InvisibleObject.h"

class DamageText : public InvisibleObject{
public:
    DamageText();
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;

    bool IsAlive();
    void AddDamage(double damage);
private:
    double damage;
    int aliveTime;
    int maxAliveTime;
};
