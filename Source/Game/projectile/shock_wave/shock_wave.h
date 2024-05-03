#pragma once
#include "../projectile.h"
#include "../../utils/once_animation_object.h"

class ShockWave : public OnceAnimationObject, public Projectile {
public:
    void Start() override;
    void Update() override;
private:
    bool activicated;
};
