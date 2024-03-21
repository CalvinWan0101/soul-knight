#include "stdafx.h"
#include "object_manager.h"

#include <algorithm>
#include <vector>

#include "../config.h"
#include "../character/player/player.h"
#include "../character/monster/monster.h"

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager* ObjectManager::Instance()
{
    if (instance == nullptr)
    {
        instance = new ObjectManager();
    }
    return instance;
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
    delete player;
    for (auto monster : monsters)
    {
        delete monster;
    }
}

void ObjectManager::SetPlayer(Player* player)
{
    this->player = player;
    objects.push_back(player);
}

void ObjectManager::AddMonster(Monster* monster)
{
    monsters.push_back(monster);
    for (auto monster : monsters)
    {
        objects.push_back(monster);
    }
}

void ObjectManager::Start()
{
    player->DefaultStart();
    for (auto monster : monsters)
    {
        monster->DefaultStart();
    }
}

void ObjectManager::Update()
{
    player->DefaultUpdate();
    for (auto monster : monsters)
    {
        monster->DefaultUpdate();
    }
}

void ObjectManager::Show()
{
    std::sort(objects.begin(), objects.end(), [](game_framework::GameObject* a, game_framework::GameObject* b)
    {
        return a->GetPoint().GetY() < b->GetPoint().GetY();
    });
    screenX = (int)player->GetPoint().GetX() - SIZE_X_HALF;
    screenY = (int)player->GetPoint().GetY() - SIZE_Y_HALF;
    for (auto object : objects)
    {
        object->Show(Point(screenX, screenY));
    }
}

void ObjectManager::KeyDown(char key)
{
    switch (key)
    {
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

void ObjectManager::KeyUp(char key)
{
    switch (key)
    {
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

void ObjectManager::SetPlayerVision(Vec vision)
{
    player->SetVision(vision);
}
