#pragma once
#include "Collectable.h"

class MpPotion : public Collectable {
public:
    MpPotion();
    void Start() override;
    void Update() override;
    void LoadResources() override;

    void Collect(Player* player) override;
};
