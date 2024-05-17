﻿#include "stdafx.h"
#include "ObjectManager.h"

#include <algorithm>
#include <vector>
#include <iostream>

#include "../utils/draw/Draw.h"
#include "StageManager.h"
#include "../config.h"
#include "../character/Player.h"
#include "../character/Monster.h"
#include "../drop/Coin.h"
#include "../pool/MonsterPool.h"
#include "../pool/ProjectilePool.h"
#include "../projectile/bullet/BadPistolBullet.h"
#include "../weapon/ranged_weapon/BadPistol.h"

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager* ObjectManager::Instance() {
    if (instance == nullptr) {
        instance = new ObjectManager();
    }
    return instance;
}

ObjectManager::ObjectManager() : isDisplayHitBox(false) {
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

Player* ObjectManager::GetPlayer() {
    return player;
}

Point* ObjectManager::GetScreenPoint() {
    return new Point(screenX, screenY);
}

void ObjectManager::AddObject(GameObject* object) {
    object->Start();
    newObjects.emplace_back(object);
}

void ObjectManager::Start() {
    AddObject(new Coin());
}

void ObjectManager::Update() {
    DeleteObsoleteElements();
    if (LButtonPressed) {
        player->Attack();
    }
    PushNewObjectsToList();
    for (auto object : objects) {
        object->Update();
    }
    CollisionDetection();
}

void ObjectManager::Show() {
    std::sort(objects.begin(), objects.end(), [](GameObject* a, GameObject* b) {
        return a->GetPosition().GetY() < b->GetPosition().GetY();
    });
    screenX = (int)player->GetPosition().GetX() - SIZE_X_HALF;
    screenY = (int)player->GetPosition().GetY() - SIZE_Y_HALF;
    StageManager::Instance()->GetStage()->Show(Point(screenX, screenY));
    for (auto object : objects) {
        object->Show(Point(screenX, screenY));
    }
    if (isDisplayHitBox) {
        for (auto object : objects) {
            object->GetHitBox().Show(Point(screenX, screenY)); // TODO: Test code for HitBox location
        }
        player->GetAlertRange().Show(Point(screenX, screenY));
    }
    game_framework::Draw::Instance()->Show();
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
    case 'Q':
        player->SetInteractive(true);
        break;
    case 'F':
        isDisplayHitBox = !isDisplayHitBox;
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
    case 'Q':
        player->SetInteractive(false);
        break;
    }
}

void ObjectManager::SetLButtonPress(bool isPress) {
    LButtonPressed = isPress;
}

void ObjectManager::SetPlayerVision(Vec vision) {
    player->SetVision(vision);
}

void ObjectManager::SetPlayerPosition(Point playerPosition) {
    player->SetPosition(&playerPosition);
}

void ObjectManager::CollisionDetection() {
    for (unsigned int i = 0; i < objects.size() - 1; i++) {
        for (unsigned int j = i + 1; j < objects.size(); j++) {
            if (objects[i]->GetHitBox().IsCollision(&objects[j]->GetHitBox())) {
                objects[i]->Collision(objects[j]);
                objects[j]->Collision(objects[i]);
            }

            if (objects[i]->HasTag(Tag::PLAYER) && objects[j]->HasTag(Tag::PLAYER_ALERTABLE)) {
                PlayerAlertable* alertableObject = dynamic_cast<PlayerAlertable*>(objects[j]);
                if (player->GetAlertRange().IsCollision(&objects[j]->GetHitBox())) {
                    alertableObject->EnterPlayerAlertRange(player);
                }
            }
            else if (objects[i]->HasTag(Tag::PLAYER_ALERTABLE) && objects[j]->HasTag(Tag::PLAYER)) {
                PlayerAlertable* alertableObject = dynamic_cast<PlayerAlertable*>(objects[i]);
                if (player->GetAlertRange().IsCollision(&objects[i]->GetHitBox())) {
                    alertableObject->EnterPlayerAlertRange(player);
                }
            }
        }
    }
}

void ObjectManager::DeleteObsoleteElements() {
    for (vector<GameObject*>::iterator object = objects.begin(); object != objects.end();) {
        if ((*object)->HasTag(Tag::REMOVE_ON_NEXT_FRAME)) {
            (*object)->RemoveTag(Tag::REMOVE_ON_NEXT_FRAME);
            if ((*object)->HasTag(Tag::PROJECTILE)) {
                ProjectilePool::Instance()->Release(dynamic_cast<Projectile*>(*object));
            }
            else if ((*object)->HasTag(Tag::MONSTER)) {
                MonsterPool::Instance()->Release(dynamic_cast<Monster*>(*object));
            }
            else {
                delete *object;
                *object = nullptr;
            }
            object = objects.erase(object);
        }
        else { ++object; }
    }
}

void ObjectManager::PushNewObjectsToList() {
    objects.insert(objects.end(), newObjects.begin(), newObjects.end());
    newObjects.clear();
}
