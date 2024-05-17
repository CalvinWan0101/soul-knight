#include "stdafx.h"
#include "StageFactory.h"

#include "implementation/stage_1/Stage_1_1.h"
#include "implementation/stage_1/Stage_1_2.h"
#include "implementation/stage_1/Stage_1_3.h"
#include "implementation/stage_1/Stage_1_4.h"

Stage* StageFactory::Create(int level, int stage) {
    if (level == 1) {
        if (stage == 1) {
            return new Stage_1_1();
        }
        if (stage == 2) {
            return new Stage_1_2();
        }
        if (stage == 3) {
            return new Stage_1_3();
        }
        if (stage == 4) {
            return new Stage_1_4();
        }
    }
    return nullptr;
}
