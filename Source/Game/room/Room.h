#pragma once
#include "RoomSize.h"
#include "../utils/Point.h"

class Room {
public:
    Room(Point leftTop, RoomSize size, Vec centerOffset);

protected:
    Point topLeft; // Outter position
    int size;
    Vec centerOffset;
};
