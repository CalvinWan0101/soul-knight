#pragma once
#include "Door.h"

class VerticalDoor3 : public Door {
public:
    void LoadResources() override;
    void SetTopLeft(Point leftTop) override;
};
