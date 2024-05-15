#pragma once
#include "Door.h"

class VerticalDoor4 : public Door {
public:
    void LoadResources() override;
    void SetTopLeft(Point leftTop) override;
};
