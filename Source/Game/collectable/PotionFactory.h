#pragma once
#include "Collectable.h"

class PotionFactory {
public:
    enum PotionType {
        HEALING,
        BIG_HEALING,
        MP,
        BIG_MP,
        COMPOSITE,
        BIG_COMPOSITE,

        Count
    };
    static Collectable* Create(PotionType type);
};
