#include "stdafx.h"
#include "DropFactory.h"

#include "Coin.h"
#include "MagicBall.h"

Drop* DropFactory::Create(DropType type) {
    switch (type) {
    case DropType::COIN:
        return new Coin();
    case DropType::MAGIC_BALL:
        return new MagicBall();
    default:
        return nullptr;
    }
}

