#include "stdafx.h"
#include "TreasureRoom.h"

#include "../manager/ObjectManager.h"
#include "../manager/StageManager.h"
#include "../shop/Businessman.h"
#include "../shop/TreasureChest.h"
#include "../utils/Rand.h"

TreasureRoom::TreasureRoom(Point leftTop, Vec centerOffset): Room(leftTop, RoomSize::MEDIUM_SIZE, centerOffset) {
    switch (Rand::Instance()->Get(0, 2)) {
    case 0:
        treasure = new Businessman(StageManager::Instance()->GetLevelNumber(),
                                   StageManager::Instance()->GetStageNumber());
        break;
    default:
        treasure = new TreasureChest(TreasureChest::BOX_ROOM);
        break;
    }
    treasure->SetPosition(topLeft + Point((this->size + 2) * 8, (this->size + 2) * 8) - centerOffset);
    ObjectManager::Instance()->AddObject(treasure);
}

TreasureRoom::~TreasureRoom() {
    treasure->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}
