#pragma once
#include "../bullet.h"

class Arrow : public Bullet {
public:
    Arrow();
    void Start() override;
    void Update() override;
};
