#include "stdafx.h"
#include "Coin.h"

#include "../manager/ObjectManager.h"

Coin::Coin() : value(1) {
}

void Coin::Start() {
    MagnetizedDrop::Start();
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

void Coin::SetValue(Material material) {
    this->value = material;
    switch (material) {
    case(Material::COPPER):
        index = 0;
        break;
    case(Material::SILVER):
        index = 1;
        break;
    case(Material::GOLD):
        index = 2;
        break;
    }
}



