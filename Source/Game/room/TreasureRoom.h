#pragma once
#include "Room.h"
#include "../utils/object/GameObject.h"

class TreasureRoom : public Room {
public:
    TreasureRoom(Point leftTop, Vec centerOffset);
    ~TreasureRoom();

private:
    GameObject* treasure;
};
