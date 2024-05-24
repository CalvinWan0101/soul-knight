#include "stdafx.h"
#include "Room.h"

Room::Room(Point leftTop, Vec centerOffset, RoomSize size, int level) : topLeft(leftTop), centerOffset(centerOffset),
                                                                        size(static_cast<int>(size)), level(level) {
}
