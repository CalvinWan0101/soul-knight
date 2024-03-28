#include "stdafx.h"
#include "object_manager.h"

#include <algorithm>
#include <vector>

#include "../config.h"
#include "../character/player/player.h"
#include "../character/monster/monster.h"
#include "../weapon/bad_pistol.h"

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager* ObjectManager::Instance() {
    if (instance == nullptr) {
        instance = new ObjectManager();
    }
    return instance;
}

ObjectManager::ObjectManager() {
}

ObjectManager::~ObjectManager() {
    for (auto object : objects) {
        delete object;
    }
}

void ObjectManager::SetPlayer(Player* player) {
    player->Start();
    this->player = player;
    objects.emplace_back(player);
}

void ObjectManager::SetGameMap(GameObject* gameMap) {
    gameMap->Start();
    this->gameMap = gameMap;
}

void ObjectManager::AddObject(GameObject* object) {
    object->Start();
    objects.emplace_back(object);
}

void ObjectManager::Start() {
}

void ObjectManager::Update() {
    DeleteObsoleteElements();
    if (LButtonPressed) {
        player->Attack();
    }
    for (auto object : objects) {
        object->Update();
    }
    CollisionDetection();
}

void ObjectManager::Show() {
    gameMap->Show(Point(screenX, screenY));
    std::sort(objects.begin(), objects.end(), [](game_framework::GameObject* a, game_framework::GameObject* b) {
        return a->GetPoint().GetY() < b->GetPoint().GetY();
    });
    screenX = (int)player->GetPoint().GetX() - SIZE_X_HALF;
    screenY = (int)player->GetPoint().GetY() - SIZE_Y_HALF;
    for (auto object : objects) {
        object->Show(Point(screenX, screenY));
    }
}

void ObjectManager::KeyDown(char key) {
    switch (key) {
    case 'A':
        player->SetSpeedX(player->GetSpeed().GetX() - 10);
        break;
    case 'D':
        player->SetSpeedX(player->GetSpeed().GetX() + 10);
        break;
    case 'W':
        player->SetSpeedY(player->GetSpeed().GetY() - 10);
        break;
    case 'S':
        player->SetSpeedY(player->GetSpeed().GetY() + 10);
        break;
    }
}

void ObjectManager::KeyUp(char key) {
    switch (key) {
    case 'A':
        player->SetSpeedX(player->GetSpeed().GetX() + 10);
        break;
    case 'D':
        player->SetSpeedX(player->GetSpeed().GetX() - 10);
        break;
    case 'W':
        player->SetSpeedY(player->GetSpeed().GetY() + 10);
        break;
    case 'S':
        player->SetSpeedY(player->GetSpeed().GetY() - 10);
        break;
    }
}

void ObjectManager::SetLButtonPress(bool isPress) {
    LButtonPressed = isPress;
}

void ObjectManager::SetPlayerVision(Vec vision) {
    player->SetVision(vision);
}

void ObjectManager::CollisionDetection() {
    for (unsigned int i = 0; i < objects.size() - 1; i++) {
        for (unsigned int j = i + 1; j < objects.size(); j++) {
            if (objects[i]->GetHitBox().IsCollision(&objects[j]->GetHitBox())) {
                objects[i]->Collision(objects[j]);
                objects[j]->Collision(objects[i]);
            }
        }
    }
}

void ObjectManager::DeleteObsoleteElements() {
    for (vector<GameObject*>::iterator object = objects.begin(); object != objects.end();) {
        if ((*object)->HasTag(Tag::REMOVE_ON_NEXT_FRAME)) {
            delete *object;
            object = objects.erase(object);
        }
        else { ++object; }
    }
}
