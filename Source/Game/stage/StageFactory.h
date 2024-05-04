#pragma once
#include "implementation/Stage_1_1.h"

class Stage;

class StageFactory {
public:
    static Stage* Create(int level, int stage);
};
