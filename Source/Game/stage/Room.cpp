#include "stdafx.h"
#include "Room.h"
#include <random>
#include "../manager/ObjectManager.h"
#include "../manager/StageManager.h"
#include "../pool/MonsterPool.h"
#include "../character/Monster.h"
#include "../character/Player.h"
#include "../utils/Rand.h"
#include "../wall/Wall.h"
#include "../wall/door/VerticalDoor1.h"
#include "../wall/door/VerticalDoor2.h"
#include "../wall/door/VerticalDoor3.h"
#include "../wall/door/VerticalDoor4.h"
#include "../wall/door/HorizontalDoor1.h"
#include "../wall/door/HorizontalDoor2.h"
#include "../wall/door/HorizontalDoor3.h"
#include "../wall/door/HorizontalDoor4.h"

Room::Room(Point topLeft, Vec centerOffset, RoomSize size, int level, std::map<MonsterType, int> monsterMap,
           bool isBossRoom):
    topLeft(topLeft),
    centerOffset(centerOffset),
    size((int)size),
    level(level),
    monsterMap(monsterMap),
    isBossRoom(isBossRoom) {
}

Room::~Room() {
    if (treasureChest) {
        treasureChest->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
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

    if (isBossRoom) {
        StageManager::Instance()->SetTransferGatePosition(
            topLeft + Point((size + 2) * 8, (size + 2) * 8) - centerOffset);
    }

    if (isBossRoom) {
        treasureChest = new TreasureChest(TreasureChest::BOSS_ROOM);
        treasureChest->SetPosition(topLeft + Point((size + 2) * 8, (size + 12) * 8) - centerOffset);
    }
    else {
        treasureChest = new TreasureChest(TreasureChest::NORMAL_ROOM);
        double minX = topLeft.GetX() + 16 - centerOffset.GetX();
        double minY = topLeft.GetY() + 16 - centerOffset.GetY();
        double maxX = topLeft.GetX() + 16 * (size + 1) - centerOffset.GetX();
        double maxY = topLeft.GetY() + 16 * (size + 1) - centerOffset.GetY();

        treasureChest->SetPosition(
            Point(Rand::Instance()->Get(minX + 16, maxX - 16), Rand::Instance()->Get(minY + 16, maxY - 16)));
    }
    ObjectManager::Instance()->AddObject(treasureChest);

    for (auto door : invisibleDoors) {
        door->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }

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
            monsters.push_back(MonsterPool::Instance()->Acquire(monster.first, 1));
        }
    }
    PlacedMonster();
    for (auto monster : monsters) {
        ObjectManager::Instance()->AddObject(monster);
    }
}

void Room::PlacedMonster() {
    double minX = topLeft.GetX() + 16 - centerOffset.GetX();
    double minY = topLeft.GetY() + 16 - centerOffset.GetY();
    double maxX = topLeft.GetX() + 16 * (size + 1) - centerOffset.GetX();
    double maxY = topLeft.GetY() + 16 * (size + 1) - centerOffset.GetY();

    for (auto monster : monsters) {
        monster->SetPosition(
            Point(Rand::Instance()->Get(minX + 16, maxX - 16), Rand::Instance()->Get(minY + 16, maxY - 16)));
    }
}

void Room::SetDoors() {
    double x = topLeft.GetX() - centerOffset.GetX();
    double y = topLeft.GetY() - centerOffset.GetY();
    Wall* leftInvisibleDoor = new Wall(Point(x, y), Point(x + 16, y + 16 * (size + 2)));
    Wall* rightInvisibleDoor = new Wall(Point(x + 16 * (size + 1), y), Point(x + 16 * (size + 2), y + 16 * (size + 2)));
    Wall* topInvisibleDoor = new Wall(Point(x, y), Point(x + 16 * (size + 2), y + 16));
    Wall* bottomInvisibleDoor = new Wall(Point(x, y + 16 * (size + 1)),
                                         Point(x + 16 * (size + 2), y + 16 * (size + 2)));
    invisibleDoors.push_back(leftInvisibleDoor);
    invisibleDoors.push_back(rightInvisibleDoor);
    invisibleDoors.push_back(topInvisibleDoor);
    invisibleDoors.push_back(bottomInvisibleDoor);
    ObjectManager::Instance()->AddObject(leftInvisibleDoor);
    ObjectManager::Instance()->AddObject(rightInvisibleDoor);
    ObjectManager::Instance()->AddObject(topInvisibleDoor);
    ObjectManager::Instance()->AddObject(bottomInvisibleDoor);

    Door* leftDoor;
    Door* rightDoor;
    Door* topDoor;
    Door* bottomDoor;

    switch (level) {
    case 1:
        leftDoor = new VerticalDoor1();
        rightDoor = new VerticalDoor1();
        topDoor = new HorizontalDoor1();
        bottomDoor = new HorizontalDoor1();
        break;
    case 2:
        leftDoor = new VerticalDoor2();
        rightDoor = new VerticalDoor2();
        topDoor = new HorizontalDoor2();
        bottomDoor = new HorizontalDoor2();
        break;
    case 3:
        leftDoor = new VerticalDoor3();
        rightDoor = new VerticalDoor3();
        topDoor = new HorizontalDoor3();
        bottomDoor = new HorizontalDoor3();
        break;
    case 4:
        leftDoor = new VerticalDoor4();
        rightDoor = new VerticalDoor4();
        topDoor = new HorizontalDoor4();
        bottomDoor = new HorizontalDoor4();
    }

    leftDoor->SetTopLeft(Point(x, y + 16 * (size / 2 - 1)));
    rightDoor->SetTopLeft(Point(x + 16 * (size + 1), y + 16 * (size / 2 - 1)));
    topDoor->SetTopLeft(Point(x + 16 * (size / 2 - 1), y));
    bottomDoor->SetTopLeft(Point(x + 16 * (size / 2 - 1), y + 16 * (size + 1)));


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
