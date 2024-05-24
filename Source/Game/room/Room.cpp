#include "stdafx.h"
#include "Room.h"

Room::Room(Point leftTop, RoomSize size, Vec centerOffset):
    topLeft(leftTop),
    size(static_cast<int>(size)),
    centerOffset(centerOffset) {
}
