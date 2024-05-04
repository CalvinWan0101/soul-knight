#pragma once
#include <vector>
#include <map>
#include "../character/MonsterType.h"
#include "../utils/Point.h"

enum class RoomSize;
class Wall;
class Monster;

class Room {
public:
    Room(Point leftTop, Vec centerOffset, RoomSize size, std::map<MonsterType, int> monsterMap);
    void IsInside();
    void IsCleared();

private:
    Point topLeft; // Outter position
    int size;
    Vec centerOffset;
    bool isInside = false;
    bool isCleared = false;
    std::vector<Wall*> doors;
    std::map<MonsterType, int> monsterMap;
    std::vector<Monster*> monsters;
    void SetMonsters();
    void PlacedMonster();
    void SetDoors();
    void RelocatePlayerToNearestEdge();
};
