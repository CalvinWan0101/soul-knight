#include "stdafx.h"

#include "Monster.h"
#include "Character.h"
#include "../projectile/Bullet.h"
#include "Player.h"
#include "../drop/DropType.h"
#include "../drop/Coin.h"
#include "../drop/MagicBall.h"
#include "../manager/ObjectManager.h"
#include "../pool/DropPool.h"
#include "../utils/Rand.h"

Monster::Monster(double level): level(level), isInitializeWeapon(false) {
    AddTag(Tag::MONSTER);
    AddTag(Tag::PLAYER_ALERTABLE);
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

void Monster::OnRemove() {
    Coin* coin = dynamic_cast<Coin*>(DropPool::Instance()->Acquire(DropType::COIN));
    coin->SetValue(static_cast<Coin::Material>(Rand::Instance()->Get(0, 2) * 2 + 1));
    coin->SetPosition(this->position + Point(Rand::Instance()->Get(-10, 10), Rand::Instance()->Get(-10, 10)));
    ObjectManager::Instance()->AddObject(coin);
    MagicBall* magicBall = dynamic_cast<MagicBall*>(DropPool::Instance()->Acquire(DropType::MAGIC_BALL));
    magicBall->SetPosition(this->position + Point(Rand::Instance()->Get(-10, 10), Rand::Instance()->Get(-10, 10)));
    ObjectManager::Instance()->AddObject(magicBall);
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
    if (this->weapon) {
        RemoveFrontChile(this->weapon);
        delete this->weapon;
        this->weapon = nullptr;
    }
    this->weapon = weapon;
    this->weapon->RemoveTag(Tag::PLAYER_WEAPON);
    this->weapon->AddTag(Tag::MONSTER_WEAPON);
    this->AddFrontChild(weapon);
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
