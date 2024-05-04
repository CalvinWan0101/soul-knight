#include "stdafx.h"
#include "Room.h"
#include "../wall/Wall.h"
#include "../character/Monster.h"
#include "../character/Player.h"
#include "../manager/ObjectManager.h"

Room::Room(Point topLeft, Vec centerOffset, RoomSize size, std::vector<Monster*> monsters): topLeft(topLeft),
    centerOffset(centerOffset),
    size((int)size),
    monsters(monsters) {
}

void Room::IsInside() {
    double x = ObjectManager::Instance()->GetPlayer()->GetPosition().GetX() + centerOffset.GetX();
    double y = ObjectManager::Instance()->GetPlayer()->GetPosition().GetY() + centerOffset.GetY();
    if (!isInside && !isCleared && x >= topLeft.GetX() && x <= topLeft.GetX() + 16 * (size + 2) && y >= topLeft.GetY()
        && y <= topLeft.GetY() + 16 * (size + 2)) {
        isInside = true;
        SetDoors();
        SetMonsters();
        // TODO: Move player inside the room
    }
}

void Room::IsCleared() {
    if (!isInside || isCleared) {
        return;
    }
    for (auto monster : monsters) {
        if (!monster->HasTag(Tag::DEAD)) {
            return;
        }
    }

    isCleared = true;
    for (auto door : doors) {
        door->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    for (auto monster : monsters) {
        monster->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void Room::SetMonsters() {
    for (auto monster : monsters) {
        ObjectManager::Instance()->AddObject(monster);
    }
}

void Room::SetDoors() {
    double x = topLeft.GetX() - centerOffset.GetX();
    double y = topLeft.GetY() - centerOffset.GetY();
    Wall* leftDoor = new Wall(Point(x, y), Point(x + 16, y + 16 * (size + 2)));
    Wall* rightDoor = new Wall(Point(x + 16 * (size + 1), y), Point(x + 16 * (size + 2), y + 16 * (size + 2)));
    Wall* topDoor = new Wall(Point(x, y), Point(x + 16 * (size + 2), y + 16));
    Wall* bottomDoor = new Wall(Point(x, y + 16 * (size + 1)), Point(x + 16 * (size + 2), y + 16 * (size + 2)));
    doors.push_back(leftDoor);
    doors.push_back(rightDoor);
    doors.push_back(topDoor);
    doors.push_back(bottomDoor);
    ObjectManager::Instance()->AddObject(leftDoor);
    ObjectManager::Instance()->AddObject(rightDoor);
    ObjectManager::Instance()->AddObject(topDoor);
    ObjectManager::Instance()->AddObject(bottomDoor);
}
