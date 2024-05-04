#include "stdafx.h"
#include "Room.h"
#include <random>
#include "../wall/Wall.h"
#include "../character/Monster.h"
#include "../character/MonsterFactory.h"
#include "../character/Player.h"
#include "../manager/ObjectManager.h"

Room::Room(Point topLeft, Vec centerOffset, RoomSize size, std::map<MonsterType, int> monsterMap): topLeft(topLeft),
    centerOffset(centerOffset),
    size((int)size),
    monsterMap(monsterMap) {
}

void Room::IsInside() {
    double x = ObjectManager::Instance()->GetPlayer()->GetPosition().GetX() + centerOffset.GetX();
    double y = ObjectManager::Instance()->GetPlayer()->GetPosition().GetY() + centerOffset.GetY();
    if (!isInside && !isCleared && x >= topLeft.GetX() && x <= topLeft.GetX() + 16 * (size + 2) && y >= topLeft.GetY()
        && y <= topLeft.GetY() + 16 * (size + 2)) {
        isInside = true;
        RelocatePlayerToNearestEdge();
        SetDoors();
        SetMonsters();
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
    for (auto monster : monsterMap) {
        for (int i = 0; i < monster.second; i++) {
            monsters.push_back(MonsterFactory::CreateMonster(monster.first, 1));
        }
    }
    PlacedMonster();
    for (auto monster : monsters) {
        ObjectManager::Instance()->AddObject(monster);
    }
}

void Room::PlacedMonster() {
    std::random_device rd;
    std::mt19937 gen(rd());

    double minX = topLeft.GetX() + 32 - centerOffset.GetX();
    double minY = topLeft.GetY() + 32 - centerOffset.GetY();
    double maxX = topLeft.GetX() + 16 * size - centerOffset.GetX();
    double maxY = topLeft.GetY() + 16 * size - centerOffset.GetY();

    std::uniform_int_distribution<> disX(minX, maxX - 1);
    std::uniform_int_distribution<> disY(minY, maxY - 1);

    for (auto monster : monsters) {
        monster->SetPosition(Point(disX(gen), disY(gen)));
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

void Room::RelocatePlayerToNearestEdge() {
    double x = topLeft.GetX() - centerOffset.GetX();
    double y = topLeft.GetY() - centerOffset.GetY();
    Point left = Point(x + 16, y + 16 * (size / 2 + 1));
    Point top = Point(x + 16 * (size / 2 + 1), y + 16);
    Point right = Point(x + 16 * (size + 1), y + 16 * (size / 2 + 1));
    Point bottom = Point(x + 16 * (size / 2 + 1), y + 16 * (size + 1));

    std::vector<Point> middlePoints = {left, top, right, bottom};
    Point playerPosition = ObjectManager::Instance()->GetPlayer()->GetPosition();
    Point result;
    double minDistance = 100000;
    for (auto point : middlePoints) {
        if (playerPosition.Distance(point) < minDistance) {
            minDistance = playerPosition.Distance(point);
            result = point;
        }
    }
    ObjectManager::Instance()->GetPlayer()->SetPosition(result);
}
