#pragma once
#include "../utils/rotatable_object.h"

class Bullet : public RotatableObject {
public:
    Bullet();
    void Start() override;
    void Update() override = 0;

    void SetDamage(int damage);
    int GetDamage();
protected:
    int damage;
};
