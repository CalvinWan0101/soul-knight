#pragma once
#include "../utils/rotatable_object.h"

class Weapon : public RotatableObject {
public:
    Weapon();
    void Start() override;
    void Update() override;
    void DefaultAttack();
    virtual void Attack() = 0;
    int GetCd();
    int GetDamage();
    int GetMpCost();
    
protected:
    double cd; // second
    int damage;
    int mpCost;
    
private:
    int cdCounter;
};
