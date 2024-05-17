#include "stdafx.h"
#include "Coin.h"

#include "../manager/ObjectManager.h"

Coin::Coin() : value(0) {
}

void Coin::Start() {
    MagnetizedDrop::Start();
    SetValue(1);
}

void Coin::Update() {
    MagnetizedDrop::Update();
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

void Coin::SetValue(int value) {
    this->value = value;
    if (value >= 10) {
        index = 2;
    }
    else if (value >= 5) {
        index = 1;
    }
    else {
        index = 0;
    }
}



