#include "stdafx.h"

#include "monster.h"
#include "../character.h"
#include "../../bullet/bullet.h"
#include "../player/player.h"

Monster::Monster() {
    AddTag(Tag::MONSTER);
}

void Monster::Start() {
    SetHitBoxByRatio(0.8, 0.5);
    Character::Start();
}

void Monster::Update() {
    Character::Update();
    if (player) {
        Vec nowSpeed = (player->GetPoint() - this->point);
        nowSpeed.SetLength(maxSpeed);
        this->speed = nowSpeed;
    }
}

void Monster::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER_BULLET)) {
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
