#pragma once
#include "Collectable.h"

class HealingPotion : public Collectable {
public:
    HealingPotion();
    void Start() override;
    void Update() override;
    void LoadResources() override;

    void Interactive(Player* player) override;
};
