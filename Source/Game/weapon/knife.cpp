#include "stdafx.h"
#include "knife.h"
#include "../character/player/player.h"


Knife::Knife() {
}

void Knife::Start() {
    Weapon::Start();
}

void Knife::Update() {
    Weapon::Update();
}

void Knife::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        Player* player = dynamic_cast<Player*>(gameObject);
        player->BeAttacked(damage);
    }
}
