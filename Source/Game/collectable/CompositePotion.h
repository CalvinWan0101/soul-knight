#pragma once
#include "Collectable.h"

class CompositePotion : public  Collectable{
public:
    CompositePotion();
    void Start() override;
    void Update() override;
    void LoadResources() override;

    void Collect(Player* player) override;
};
