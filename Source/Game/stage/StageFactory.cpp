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
    switch (level * 10 + stage) {
    case 11: return new Stage_1_1();
    case 12: return new Stage_1_2();
    case 13: return new Stage_1_3();
    case 14: return new Stage_1_4();
    case 15: return new Stage_1_5();
    case 21: return new Stage_2_1();
    case 22: return new Stage_2_2();
    case 23: return new Stage_2_3();
    case 24: return new Stage_2_4();
    case 25: return new Stage_2_5();
    case 31: return new Stage_3_1();
    case 32: return new Stage_3_2();
    case 33: return new Stage_3_3();
    case 34: return new Stage_3_4();
    case 35: return new Stage_3_5();
    case 36: return new Stage_3_6();
    default: return nullptr;
    }
}
