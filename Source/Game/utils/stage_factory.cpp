#include "stdafx.h"
#include "stage_factory.h"

Stage* StageFactory::Create(int level, int stage) {
    if (level == 1) {
        if (stage == 1) {
            return new Stage_1_1();
        }
    }
    return nullptr;
}
