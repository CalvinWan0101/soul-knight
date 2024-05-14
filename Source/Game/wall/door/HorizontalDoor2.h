#pragma once
#include "Door.h"

class HorizontalDoor2 : public Door {
public:
    void LoadResources() override;
    void SetTopLeft(Point leftTop) override;
};
