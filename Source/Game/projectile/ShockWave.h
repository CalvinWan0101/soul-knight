#pragma once
#include "Projectile.h"
#include "../utils/object/OnceAnimationObject.h"

class ShockWave : public OnceAnimationObject, public Projectile {
public:
    void Start() override;
    void Update() override;
private:
    bool activicated;
};
