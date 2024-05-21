#include "stdafx.h"
#include "Coin.h"

#include "../manager/ObjectManager.h"
#include "../utils/Rand.h"

Coin::Coin() : value(1) {
    SetDropType(DropType::COIN);
}

void Coin::Start() {
    Drop::Start();
    index = Rand::Instance()->Get(0,2);
    switch (index) {
    case 0:
        value = 1;
        break;
    case 1:
        value = 3;
        break;
    case 2:
        value = 5;
        break;
    }
}

void Coin::Update() {
    Drop::Update();
}

void Coin::LoadResources() {
    AddAnimation(
        {"Resources/object/copper_coin/1.bmp",
        "Resources/object/copper_coin/2.bmp",
        "Resources/object/copper_coin/3.bmp",
        "Resources/object/copper_coin/4.bmp"},
        RGB(255,255,255),
        150,
        false
        );
    AddAnimation(
        {"Resources/object/silver_coin/1.bmp",
        "Resources/object/silver_coin/2.bmp",
        "Resources/object/silver_coin/3.bmp",
        "Resources/object/silver_coin/4.bmp"},
        RGB(255,255,255),
        150,
        false
        );
    AddAnimation(
        {"Resources/object/gold_coin/1.bmp",
        "Resources/object/gold_coin/2.bmp",
        "Resources/object/gold_coin/3.bmp",
        "Resources/object/gold_coin/4.bmp"},
        RGB(255,255,255),
        150,
        false
        );
}

void Coin::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
        ObjectManager::Instance()->MakeMoney(value);
    }
}