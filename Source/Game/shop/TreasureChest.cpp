#include "stdafx.h"
#include "TreasureChest.h"

#include "../collectable/PotionFactory.h"
#include "../drop/Coin.h"
#include "../manager/ObjectManager.h"
#include "../pool/DropPool.h"
#include "../utils/Rand.h"
#include "../weapon/WeaponFactory.h"

TreasureChest::TreasureChest(Type type) : OnceAnimationObject(), isCreateContents(false) {
    this->type = type;
}

void TreasureChest::Start() {
    OnceAnimationObject::Start();
    SetInteractiveText("Open The Box", InteractiveText::COMMON);
    SetHitBoxByRatio(0.5, 0.5);
}

void TreasureChest::Update() {
    OnceAnimationObject::Update();
    if (isAnimationFinished && !isCreateContents) {
        isCreateContents = true;
        CreateContents();
    }
}

void TreasureChest::LoadResources() {
    SetAnimation({
                     "Resources/object/treasure_chest/animate/1.bmp",
                     "Resources/object/treasure_chest/animate/2.bmp",
                     "Resources/object/treasure_chest/animate/3.bmp",
                     "Resources/object/treasure_chest/animate/4.bmp",
                     "Resources/object/treasure_chest/animate/5.bmp",
                     "Resources/object/treasure_chest/animate/6.bmp",
                     "Resources/object/treasure_chest/animate/7.bmp",
                     "Resources/object/treasure_chest/animate/8.bmp",
                     "Resources/object/treasure_chest/animate/9.bmp",
                     "Resources/object/treasure_chest/animate/10.bmp"
                 }, 30, RGB(255, 255, 255));
}


void TreasureChest::Interactive(Player* player) {
    playedAnimation = true;
    RemoveTag(Tag::INTERACTABLE);
}

void TreasureChest::CreateContents() {
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

void TreasureChest::CreateContentsNormalRoom() {
    int rand = Rand::Instance()->Get(1, 10);
    if (rand <= 7) {
        GameObject* contents;
        for (int i = 0; i < Rand::Instance()->Get(3, 9); i++) {
            contents = DropPool::Instance()->Acquire(DropType::COIN);
            contents->SetPosition(
                this->position + Point(Rand::Instance()->Get(-30, 30), Rand::Instance()->Get(-30, 30)));
            ObjectManager::Instance()->AddObject(contents);
        }
        for (int i = 0; i < Rand::Instance()->Get(3, 9); i++) {
            contents = DropPool::Instance()->Acquire(DropType::MAGIC_BALL);
            contents->SetPosition(
                this->position + Point(Rand::Instance()->Get(-30, 30), Rand::Instance()->Get(-30, 30)));
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

void TreasureChest::CreateContentsBoxRoom() {
    int rand = Rand::Instance()->Get(1, 10);
    if (rand <= 4) {
        CreatePotion();
    }
    else if (rand <= 10) {
        CreateWeapon();
    }
}

void TreasureChest::CreateContentsBossRoom() {
    CreateWeapon();
}

void TreasureChest::CreatePotion() {
    GameObject* contents;
    int potionId = Rand::Instance()->Get(0, static_cast<int>(PotionFactory::PotionType::Count) - 1);
    contents = PotionFactory::Create(static_cast<PotionFactory::PotionType>(potionId));
    contents->SetPosition(this->position);
    ObjectManager::Instance()->AddObject(contents);
}

void TreasureChest::CreateWeapon() {
    GameObject* contents;
    int weaponId = Rand::Instance()->Get(0, WeaponFactory::Name::Count - 1);
    contents = WeaponFactory::Create(static_cast<WeaponFactory::Name>(weaponId));
    contents->SetPosition(this->position);
    ObjectManager::Instance()->AddObject(contents);
}
