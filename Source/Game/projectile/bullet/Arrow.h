#pragma once
#include "../Bullet.h"

class Arrow : public Bullet {
public:
    Arrow();
    void Start() override;
    void Update() override;
    void LoadResources() override;
};
