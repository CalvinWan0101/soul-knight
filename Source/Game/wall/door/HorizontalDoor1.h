#pragma once
#include "Door.h"

class HorizontalDoor1 : public Door {
public:
    void LoadResources() override;
    void SetTopLeft(Point leftTop) override;
};
