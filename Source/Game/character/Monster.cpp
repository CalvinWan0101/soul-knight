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

Monster::Monster(double level, bool isMeleeAttackMonster): level(level), isInitializeWeapon(false),
                                                           damageText(nullptr),
                                                           isMeleeAttackMonster(isMeleeAttackMonster),
                                                           collideOnObstacle(false) {
    AddTag(Tag::MONSTER);
    AddTag(Tag::PLAYER_ALERTABLE);
}

void Monster::Start() {
    Character::Start();
    SetHitBoxByRatio(1, 1);
    isOnDeadTrigger = false;
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
        AutoMationMove();
    }
    else {
        this->vision = this->speed;
    }

    if (!isOnDeadTrigger && HasTag(Tag::DEAD)) {
        isOnDeadTrigger = true;
        OnDead();
    }
    Character::Update();
}

void Monster::OnRemove() {
    if (!isOnDeadTrigger) {
        isOnDeadTrigger = true;
        OnDead();
    }
}

void Monster::OnDead() {
    Coin* coin = dynamic_cast<Coin*>(DropPool::Instance()->Acquire(DropType::COIN));
    coin->SetPosition(this->position + Point(Rand::Instance()->Get(-10, 10), Rand::Instance()->Get(-10, 10)));
    ObjectManager::Instance()->AddObject(coin);
    MagicBall* magicBall = dynamic_cast<MagicBall*>(DropPool::Instance()->Acquire(DropType::MAGIC_BALL));
    magicBall->SetPosition(this->position + Point(Rand::Instance()->Get(-10, 10), Rand::Instance()->Get(-10, 10)));
    ObjectManager::Instance()->AddObject(magicBall);
}

void Monster::Collision(GameObject* gameObject) {
    Character::Collision(gameObject);
    if (gameObject->HasTag(Tag::PLAYER_ATTACK)) {
        Injuried(dynamic_cast<Projectile*>(gameObject)->GetDamage());
    }
    if (gameObject->HasTag(Tag::OBSTACLE)) {
        collideOnObstacle = true;
    }
}

void Monster::AutoMationMove() {
    Vec playerOrientation = (player->GetPosition() - this->position);
    playerOrientation.SetLength(maxSpeed);
    this->vision = playerOrientation;
    AutoMation();
    if (isMeleeAttackMonster) {
        this->speed = playerOrientation;
        return;
    }
    if (Rand::Instance()->Get(0, 99) == 0 || collideOnObstacle) {
        collideOnObstacle = false;
        this->speed = Vec(Rand::Instance()->Get(-9, 9), Rand::Instance()->Get(-9, 9));
        this->speed.SetLength(maxSpeed);
        this->vision = this->speed;
    }
}


void Monster::EnterPlayerAlertRange(Player* player) {
    if (!this->player) {
        this->player = player;
    }
}

void Monster::SetWeapon(Weapon* weapon) {
    if (this->weapon1) {
        RemoveFrontChile(this->weapon1);
        delete this->weapon1;
        this->weapon1 = nullptr;
    }
    this->weapon1 = weapon;
    this->weapon1->RemoveTag(Tag::PLAYER_WEAPON);
    this->weapon1->AddTag(Tag::MONSTER_WEAPON);
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

void Monster::Injuried(double damage) {
    if (this->HasTag(Tag::DEAD)) {
        return;
    }
    this->hp -= damage;
    if (this->hp < 0) {
        this->hp = 0;
    }

    if (!damageText) {
        CreateNewDamageText();
    }

    if (damageText->IsAlive() == false) {
        CreateNewDamageText();
    }

    damageText->AddDamage(damage);
}


void Monster::SetMonsterType(MonsterType type) {
    monsterType = static_cast<int>(type);
}

void Monster::CreateNewDamageText() {
    damageText = new DamageText();
    damageText->SetPosition(position);
    ObjectManager::Instance()->AddObject(damageText);
}
