#pragma once
#include "../utils/rotatable_object.h"

class Weapon : public RotatableObject {
public:
    Weapon();
    void Start() override = 0;
    void Update() override;
    void DefaultAttack();
    virtual void Attack() = 0;
    int GetCd();
    int GetDamage();
    int GetMpCost();
    
protected:
    double cd; // second
    
private:
    int cdCounter;
    int damage;
    int mpCost;
};
