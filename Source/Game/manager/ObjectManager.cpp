#include "stdafx.h"
#include "ObjectManager.h"

#include <algorithm>
#include <vector>
#include <iostream>

#include "../utils/draw/Draw.h"
#include "StageManager.h"
#include "../stage/Stage.h"
#include "../config.h"
#include "../character/Player.h"
#include "../character/Monster.h"
#include "../character/boss/zulan_the_colossus/ZulanTheColossus.h"
#include "../character/player/alchemist/Alchemist.h"
#include "../character/player/knight/Knight.h"
#include "../character/player/priestess/Priestess.h"
#include "../collectable/BigCompositePotion.h"
#include "../collectable/BigHealingPotion.h"
#include "../collectable/BigMpPotion.h"
#include "../collectable/Collectable.h"
#include "../collectable/CompositePotion.h"
#include "../collectable/HealingPotion.h"
#include "../collectable/MpPotion.h"
#include "../drop/Coin.h"
#include "../pool/DropPool.h"
#include "../pool/MonsterPool.h"
#include "../pool/ProjectilePool.h"
#include "../projectile/effect/PoisonEffect.h"
#include "../projectile/shock_wave/BlowUp.h"
#include "../shop/TreasureChest.h"
#include "../shop/Businessman.h"
#include "../shop/DisplayStand.h"
#include "../shop/PotionVendingMachine.h"
#include "../shop/WeaponVendingMachine.h"
#include "../weapon/melee_weapon/Hammer.h"
#include "../weapon/melee_weapon/Hoe.h"
#include "../weapon/melee_weapon/Spear.h"
#include "../weapon/ranged_weapon/BadPistol.h"
#include "../weapon/ranged_weapon/Bow.h"
#include "../weapon/ranged_weapon/Dart.h"
#include "../weapon/ranged_weapon/Pistol.h"

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager* ObjectManager::Instance() {
    if (instance == nullptr) {
        instance = new ObjectManager();
    }
    return instance;
}

ObjectManager::ObjectManager() : LButtonPressed(false) , isDisplayHitBox(false), playerType(PlayerType::KNIGHT) {
}

ObjectManager::~ObjectManager() {
    for (auto object : objects) {
        delete object;
    }
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
    switch (playerType)
    {
    case PlayerType::KNIGHT:
        this->player = new Knight();
        break;
    case PlayerType::ALCHEMIST:
        this->player = new Alchemist();
        break;
    case PlayerType::PRIESTESS:
        this->player = new Priestess();
        break;
    }
    this->player->Start();
    objects.emplace_back(this->player);
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
    if (player->GetHP() <= 0)
    {
        return;
    }
    switch (key) {
    case 'A':
        player->SetSpeedX(player->GetSpeed().GetX() - 5);
        break;
    case 'D':
        player->SetSpeedX(player->GetSpeed().GetX() + 5);
        break;
    case 'W':
        player->SetSpeedY(player->GetSpeed().GetY() - 5);
        break;
    case 'S':
        player->SetSpeedY(player->GetSpeed().GetY() + 5);
        break;
    case 'E':
        player->SwitchWeapon();
        break;
    case 'F':
        player->SetInteractive(true);
        break;
    case 'Q':
        player->UseSkill();
        break;
    case '1':
        isDisplayHitBox = !isDisplayHitBox;
        break;
    case '2': {
        player->RecoverMP(100);
        break;
    }
    case '3': {
        player->Healing(1);
        break;
    }
    case '4': {
        MakeMoney(100);
        break;
    }
    case '5': {
        player->SwitchInvincibleMode();
        break;
    }
    case '6': {
        player->SwitchThroughWallMode();
        break;
    }
    case '7': {
        GameObject* box = new TreasureChest(TreasureChest::BOSS_ROOM);
        box->SetPosition(player->GetPosition());
        AddObject(box);
        break;
    }
    }
}

void ObjectManager::KeyUp(char key) {
    if (player->GetHP() <= 0)
    {
        return;
    }
    switch (key) {
    case 'A':
        player->SetSpeedX(player->GetSpeed().GetX() + 5);
        break;
    case 'D':
        player->SetSpeedX(player->GetSpeed().GetX() - 5);
        break;
    case 'W':
        player->SetSpeedY(player->GetSpeed().GetY() + 5);
        break;
    case 'S':
        player->SetSpeedY(player->GetSpeed().GetY() - 5);
        break;
    case 'F':
        player->SetInteractive(false);
        break;
    }
}

void ObjectManager::SetLButtonPress(bool isPress) {
    if (player->GetHP() <= 0)
    {
        return;
    }
    LButtonPressed = isPress;
}

void ObjectManager::SetPlayerVision(Vec vision) {
    if (player->GetHP() <= 0)
    {
        return;
    }
    player->SetVision(vision);
}

void ObjectManager::SetPlayerPosition(Point playerPosition) {
    player->SetPosition(&playerPosition);
}

void ObjectManager::MakeMoney(int money) {
    wallet.MakeMoney(money);
}

bool ObjectManager::SpendMoney(int money) {
    return wallet.SpendMoney(money);
}

int ObjectManager::GetMoney() {
    return wallet.GetMoney();
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
            (*object)->OnRemove();
            if ((*object)->HasTag(Tag::PROJECTILE)) {
                ProjectilePool::Instance()->Release(dynamic_cast<Projectile*>(*object));
            }
            else if ((*object)->HasTag(Tag::MONSTER)) {
                MonsterPool::Instance()->Release(dynamic_cast<Monster*>(*object));
            }
            else if ((*object)->HasTag(Tag::DROP)) {
                DropPool::Instance()->Release(dynamic_cast<Drop*>(*object));
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

void ObjectManager::SetPlayerType(PlayerType playerType)
{
    this->playerType = playerType;
}

PlayerType ObjectManager::GetPlayerType()
{
    return playerType;
}

