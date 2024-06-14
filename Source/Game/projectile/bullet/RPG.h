#pragma once
#include "../Bullet.h"

class RPG : public Bullet {
public:
    RPG();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void OnRemove() override;
};
