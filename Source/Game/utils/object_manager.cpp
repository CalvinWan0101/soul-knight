#include "stdafx.h"
#include "object_manager.h"

#include <algorithm>
#include <vector>

#include "../config.h"
#include "../character/player/player.h"
#include "../character/monster/monster.h"

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
    // delete player;
    // for (auto monster : monsters)
    // {
    //     delete monster;
    // }
    for (auto object : objects) {
        delete object;
    }
}

void ObjectManager::SetPlayer(Player* player) {
    player->DefaultStart();
    this->player = player;
    objects.emplace_back(player);
}

void ObjectManager::AddMonster(Monster* monster) {
    monster->DefaultStart();
    monsters.emplace_back(monster);
    objects.emplace_back(monster);
}

void ObjectManager::AddPlayerBullets(Bullet* bullet, Vec offset) {
    bullet->DefaultStart();
    bullet->GetPoint() = player->GetPoint() + offset;
    playerBullets.emplace_back(bullet);
    objects.emplace_back(bullet);
}

void ObjectManager::Start() {
}

void ObjectManager::Update() {
    // player->DefaultUpdate();
    if (LButtonPressed) {
        player->Attack();
    }
    // for (auto monster : monsters) {
    //     monster->DefaultUpdate();
    // }
    // for (auto bullet : playerBullets) {
    //     bullet->DefaultUpdate();
    // }
    // TODO: maybe have error ?
    for(auto object : objects)
    {
        object->DefaultUpdate();
    }
}

void ObjectManager::Show() {
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
