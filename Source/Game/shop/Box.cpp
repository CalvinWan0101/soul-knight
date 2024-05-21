#include "stdafx.h"
#include "Box.h"

#include "../collectable/PotionFactory.h"
#include "../drop/Coin.h"
#include "../manager/ObjectManager.h"
#include "../pool/DropPool.h"
#include "../utils/Rand.h"
#include "../weapon/WeaponFactory.h"

Box::Box(Type type) : OnceAnimationObject(), isCreateContents(false) {
    this->type = type;
}

void Box::Start() {
    OnceAnimationObject::Start();
    SetInteractiveText("Open The Box", InteractiveText::COMMON);
    SetHitBoxByRatio(0.5, 0.5);
}

void Box::Update() {
    OnceAnimationObject::Update();
    if (isAnimationFinished && !isCreateContents) {
        isCreateContents = true;
        CreateContents();
    }
}

void Box::LoadResources() {
    SetAnimation({
        "Resources/object/box/animate/1.bmp",
        "Resources/object/box/animate/2.bmp",
        "Resources/object/box/animate/3.bmp",
        "Resources/object/box/animate/4.bmp",
        "Resources/object/box/animate/5.bmp",
        "Resources/object/box/animate/6.bmp",
        "Resources/object/box/animate/7.bmp",
        "Resources/object/box/animate/8.bmp",
        "Resources/object/box/animate/9.bmp",
        "Resources/object/box/animate/10.bmp"}, 30, RGB(255,255,255));
}


void Box::Interactive(Player* player) {
    playedAnimation = true;
    RemoveTag(Tag::INTERACTABLE);
}

void Box::CreateContents() {
    switch (type) {
    case NORMAL_ROOM:
        CreateContentsNormalRoom();
        break;
    case BOX_ROOM:
        CreateContentsBoxRoom();
        break;
    case BOSS_ROOM:
        CreateContentsBossRoom();
    }
}

void Box::CreateContentsNormalRoom() {
    int rand = Rand::Instance()->Get(1,10);
    if (rand <= 7) {
        GameObject* contents;
        for (int i = 0 ; i < Rand::Instance()->Get(3,9); i++) {
            contents = DropPool::Instance()->Acquire(DropType::COIN);
            contents->SetPosition(this->position + Point(Rand::Instance()->Get(-30,30), Rand::Instance()->Get(-30,30)));
            ObjectManager::Instance()->AddObject(contents);
        }
        for (int i = 0 ; i < Rand::Instance()->Get(3,9); i++) {
            contents = DropPool::Instance()->Acquire(DropType::MAGIC_BALL);
            contents->SetPosition(this->position + Point(Rand::Instance()->Get(-30,30), Rand::Instance()->Get(-30,30)));
            ObjectManager::Instance()->AddObject(contents);
        }
    }
    else if (rand <= 9) {
        CreatePotion();
    }
    else if (rand <= 10) {
        CreateWeapon();
    }
}

void Box::CreateContentsBoxRoom() {
    int rand = Rand::Instance()->Get(1,10);
    if (rand <= 4) {
        CreatePotion();
    }
    else if (rand <= 10) {
        CreateWeapon();
    }
}

void Box::CreateContentsBossRoom() {
    CreateWeapon();
}

void Box::CreatePotion() {
    GameObject* contents;
    int potionId = Rand::Instance()->Get(0, static_cast<int>(PotionFactory::PotionType::Count) - 1);
    contents = PotionFactory::Create(static_cast<PotionFactory::PotionType>(potionId));
    contents->SetPosition(this->position);
    ObjectManager::Instance()->AddObject(contents);
}

void Box::CreateWeapon() {
    GameObject* contents;
    int weaponId = Rand::Instance()->Get(0, WeaponFactory::Name::Count - 1);
    contents = WeaponFactory::Create(static_cast<WeaponFactory::Name>(weaponId));
    contents->SetPosition(this->position);
    ObjectManager::Instance()->AddObject(contents);
}




