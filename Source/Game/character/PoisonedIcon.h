#pragma once
#include "../utils/object/GeneralObject.h"

class PoisonedIcon : public GeneralObject {
public:
    PoisonedIcon();
    void LoadResources() override;
};
