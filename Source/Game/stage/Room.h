#pragma once
#include <vector>
#include "../utils/Point.h"

enum class RoomSize;
class Wall;
class Monster;

class Room {
public:
    Room(Point leftTop, Vec centerOffset, RoomSize size, std::vector<Monster*> monsters);
    void IsInside();
    void IsCleared();

private:
    Point topLeft; // Outter position
    int size;
    Vec centerOffset;
    bool isInside = false;
    bool isCleared = false;
    std::vector<Wall*> doors;
    std::vector<Monster*> monsters;
    void SetMonsters();
    void SetDoors();
    void RelocatePlayerToNearestEdge();
};
