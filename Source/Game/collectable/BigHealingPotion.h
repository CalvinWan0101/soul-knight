#pragma once
#include "Collectable.h"

class BigHealingPotion : public Collectable {
public:
    BigHealingPotion();
    void Start() override;
    void Update() override;
    void LoadResources() override;

    void Interactive(Player* player) override;
};
