#pragma once
#include "Door.h"

class HorizontalDoor3 : public Door {
public:
    void LoadResources() override;
    void SetTopLeft(Point leftTop) override;
};
