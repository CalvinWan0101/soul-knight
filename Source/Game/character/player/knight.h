#pragma once
#include "player.h"

class Knight : public Player {
public:
    Knight();
    void Start() override;
    void Update() override;
};
