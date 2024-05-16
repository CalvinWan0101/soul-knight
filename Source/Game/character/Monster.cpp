#include "stdafx.h"

#include "Monster.h"
#include "Character.h"
#include "../projectile/Bullet.h"
#include "Player.h"

Monster::Monster(double level): level(level), isInitializeWeapon(false) {
    AddTag(Tag::MONSTER);
}

void Monster::Start() {
    Character::Start();
    SetHitBoxByRatio(1, 1);
    if (!isInitializeWeapon) {
        isInitializeWeapon = true;
        InitializeWeapon();
    }
}

void Monster::Update() {
    if (this->hp <= 0) {
        this->vision = this->speed;
        this->speed.SetVec(0.0, 0.0);
    }
    else if (player) {
        Vec playerOrientation = (player->GetPosition() - this->position);
        playerOrientation.SetLength(maxSpeed);
        this->speed = playerOrientation;
        this->vision = playerOrientation;
        AutoMation();
    }
    else {
        this->vision = this->speed;
    }
    Character::Update();
}

void Monster::Collision(GameObject* gameObject) {
    Character::Collision(gameObject);
    if (gameObject->HasTag(Tag::PLAYER_ATTACK)) {
        this->hp = this->hp - dynamic_cast<Projectile*>(gameObject)->GetDamage();
    }
}

void Monster::EnterPlayerAlertRange(Player* player) {
    if (!this->player) {
        this->player = player;
    }
}

void Monster::SetWeapon(Weapon* weapon) {
    if (!this->weapon) {
        this->weapon = weapon;
        this->weapon->RemoveTag(Tag::PLAYER_WEAPON);
        this->weapon->AddTag(Tag::MONSTER_WEAPON);
        this->AddFrontChild(weapon);
    }
}

void Monster::SetLevel(double level) {
    this->level = level;
}

void Monster::Reset() {
    this->hp = maxHp;
    this->state = IDLE;
    this->RemoveTag(Tag::DEAD);
}

MonsterType Monster::GetMonsterType() {
    return static_cast<MonsterType>(monsterType);
}

void Monster::SetMonsterType(MonsterType type) {
    monsterType = static_cast<int>(type);
}
