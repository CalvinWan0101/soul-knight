#pragma once
#include "../utils/rotatable_object.h"

class Bullet : public RotatableObject {
public:
    Bullet();
    void Start() override = 0;
    void Update() override = 0;
};
