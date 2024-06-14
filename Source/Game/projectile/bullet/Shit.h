#pragma once
#include "../Bullet.h"

class Shit : public Bullet {
public:
    Shit();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void OnRemove() override;
};
