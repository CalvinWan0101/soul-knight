#include "stdafx.h"
#include "Coin.h"

Coin::Coin() {
    
}

void Coin::Start() {
    MagnetizedDrop::Start();
}

void Coin::Update() {
    MagnetizedDrop::Update();
}

void Coin::LoadResources() {
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
    }
}


