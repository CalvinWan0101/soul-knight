#pragma once
#include "Collectable.h"

class BigCompositePotion : public Collectable {
public:
    BigCompositePotion();
    void Start() override;
    void Update() override;
    void LoadResources() override;

    void Interactive(Player* player) override;
};
