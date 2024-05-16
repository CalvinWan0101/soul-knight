#include "stdafx.h"
#include "StageFactory.h"

#include "implementation/Stage_1_1.h"
#include "implementation/Stage_1_2.h"

Stage* StageFactory::Create(int level, int stage) {
    if (level == 1) {
        if (stage == 1) {
            return new Stage_1_1();
        }
        if (stage == 2) {
            return new Stage_1_2();
        }
    }
    return nullptr;
}
