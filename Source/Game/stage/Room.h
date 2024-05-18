#pragma once
#include <vector>
#include <map>
#include "../character/MonsterType.h"
#include "../utils/Point.h"

class Door;
enum class RoomSize;
class Wall;
class Monster;

class Room {
public:
    Room(Point leftTop, Vec centerOffset, RoomSize size, int level, std::map<MonsterType, int> monsterMap, bool isBossRoom = false);
    void IsInside();
    void IsCleared();

private:
    Point topLeft; // Outter position
    int size;
    int level;
    bool isBossRoom = false;
    Vec centerOffset;
    bool isInside = false;
    bool isCleared = false;
    std::vector<Wall*> invisibleDoors;
    std::vector<Door*> doors;
    std::map<MonsterType, int> monsterMap;
    std::vector<Monster*> monsters;
    void SetMonsters();
    void PlacedMonster();
    void SetDoors();
    void RelocatePlayerToNearestEdge();
};
