#pragma once
#include "Projectile.h"
#include "../utils/object/RotatableObject.h"

class Bullet : public RotatableObject, public Projectile{
public:
    Bullet();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
};
