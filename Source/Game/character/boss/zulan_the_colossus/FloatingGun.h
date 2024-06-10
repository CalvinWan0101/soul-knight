#pragma once
#include "../../Monster.h"
#include "../../../utils/object/RotatableObject.h"

class FloatingGunState;

class FloatingGun : public RotatableObject
{
public:
    FloatingGun(Monster* author, int id);
    ~FloatingGun() override;
    void Start() override;
    void Update() override;
    void LoadResources() override;

    double GetMaxSpeed();
    
    bool IsIdle();
    void SetIsIdle();
    void SwitchIdleState();
    void SwitchAttackState();
    void SwitchControlState();

    void Attack();
    void AttackFast();
    
    Monster* GetAuthor();
    Vec GetIdleOffset();
private:
    bool idleFlag;
    FloatingGunState* state;
    FloatingGunState* idleState;
    FloatingGunState* attackState;
    FloatingGunState* controlState;
    FloatingGunState* circleAttackState;
    Vec idleOffset;
    Monster* author;
    double maxSpeed;
};
