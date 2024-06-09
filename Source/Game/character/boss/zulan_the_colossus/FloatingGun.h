#pragma once
#include "../../Monster.h"
#include "../../../utils/object/RotatableObject.h"

class FloatingGunState;

class FloatingGun : public RotatableObject
{
public:
    FloatingGun(Monster* author, int id);
    ~FloatingGun();
    void Start() override;
    void Update() override;
    void LoadResources() override;

    bool IsIdle();
    void SetIsIdle();
    void SwitchIdleState();

    void Attack();
    
    Monster* GetAuthor();
    Vec GetIdleOffset();
private:
    bool idleFlag;
    FloatingGunState* state;
    FloatingGunState* idleState;
    Vec idleOffset;
    Monster* author;
};
