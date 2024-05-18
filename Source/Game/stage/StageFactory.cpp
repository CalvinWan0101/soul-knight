#include "stdafx.h"
#include "StageFactory.h"

#include "implementation/stage_1/Stage_1_1.h"
#include "implementation/stage_1/Stage_1_2.h"
#include "implementation/stage_1/Stage_1_3.h"
#include "implementation/stage_1/Stage_1_4.h"
#include "implementation/stage_1/Stage_1_5.h"
#include "implementation/stage_2/Stage_2_1.h"
#include "implementation/stage_2/Stage_2_2.h"
#include "implementation/stage_2/Stage_2_3.h"
#include "implementation/stage_2/Stage_2_4.h"
#include "implementation/stage_2/Stage_2_5.h"
#include "implementation/stage_3/Stage_3_1.h"
#include "implementation/stage_3/Stage_3_2.h"
#include "implementation/stage_3/Stage_3_3.h"
#include "implementation/stage_3/Stage_3_4.h"
#include "implementation/stage_3/Stage_3_5.h"
#include "implementation/stage_3/Stage_3_6.h"

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
        if (stage == 5) {
            return new Stage_1_5();
        }
    }
    if (level == 2) {
        if (stage == 1) {
            return new Stage_2_1();
        }
        if (stage == 2) {
            return new Stage_2_2();
        }
        if (stage == 3) {
            return new Stage_2_3();
        }
        if (stage == 4) {
            return new Stage_2_4();
        }
        if (stage == 5) {
            return new Stage_2_5();
        }
    }
    if (level == 3) {
        if (stage == 1) {
            return new Stage_3_1();
        }
        if (stage == 2) {
            return new Stage_3_2();
        }
        if (stage == 3) {
            return new Stage_3_3();
        }
        if (stage == 4) {
            return new Stage_3_4();
        }
        if (stage == 5) {
            return new Stage_3_5();
        }
        if (stage == 6) {
            return new Stage_3_6();
        }
    }
    return nullptr;
}
