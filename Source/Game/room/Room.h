#pragma once
#include "RoomSize.h"
#include "../utils/Point.h"

class Room {
public:
    Room(Point leftTop, Vec centerOffset, RoomSize size, int level);

protected:
    Point topLeft; // Outter position
    int size;
    int level;
    Vec centerOffset;
};
