#pragma once
#include "projectile.h"
#include "../utils/object/rotatable_object.h"

class Bullet : public RotatableObject, public Projectile{
public:
    Bullet();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
};
