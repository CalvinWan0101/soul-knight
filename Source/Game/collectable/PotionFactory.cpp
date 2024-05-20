#include "stdafx.h"
#include "PotionFactory.h"

#include "BigCompositePotion.h"
#include "BigHealingPotion.h"
#include "BigMpPotion.h"
#include "CompositePotion.h"
#include "HealingPotion.h"
#include "MpPotion.h"

Collectable* PotionFactory::Create(PotionType type) {
    switch (type) {
    case HEALING:
        return new HealingPotion();
    case BIG_HEALING:
        return new BigHealingPotion();
    case MP:
        return new MpPotion();
    case BIG_MP:
        return new BigMpPotion();
    case COMPOSITE:
        return new CompositePotion();
    case BIG_COMPOSITE:
        return new BigCompositePotion();
    default:
        return nullptr;
    }
}
