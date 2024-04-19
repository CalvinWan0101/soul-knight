#include "stdafx.h"

#include "monster.h"
#include "../character.h"
#include "../../bullet/bullet.h"
#include "../player/player.h"

Monster::Monster() {
    AddTag(Tag::MONSTER);
}

void Monster::Start() {
    SetHitBoxByRatio(1, 1);
    Character::Start();
}

void Monster::Update() {
    if (this->hp <= 0) {
        this->vision = this->speed;
        this->speed.SetVec(0.0, 0.0);
    }
    else if (player) {
        Vec playerOrientation = (player->GetPoint() - this->point);
        playerOrientation.SetLength(maxSpeed);
        this->speed = playerOrientation;
        this->vision = playerOrientation;
        Attack();
    }
    else {
        this->vision = this->speed;
    }
    Character::Update();
}

void Monster::Collision(GameObject* gameObject) {
    Character::Collision(gameObject);
    if (gameObject->HasTag(Tag::PLAYER_ATTACK)) {
        this->hp = this->hp - dynamic_cast<Bullet*>(gameObject)->GetDamage();
    }
}

void Monster::EnterPlayerAlertRange(Player* player) {
    if (!this->player) {
        this->player = player;
    }
}

void Monster::SetWeapon(Weapon* weapon) {
    this->weapon = weapon;
    this->AddFrontChild(weapon);
}
