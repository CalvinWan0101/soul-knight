#include "stdafx.h"
#include "DevilsSnare.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/RedRectangleBullet.h"
#include "../../../../weapon/melee_weapon/Hammer.h"
#include "../../../../weapon/ranged_weapon/UfoWeapon.h"

DevilsSnare::DevilsSnare(double level = 1) : Monster(level), timer(0), poisonNeedleCoolDown(0), poisonNeedleNumber(0) {
}

DevilsSnare::~DevilsSnare() {
}

void DevilsSnare::Start() {
    Monster::Start();
    this->maxHp = 552 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 0.0001;
    SetMonsterType(MonsterType::DEVELS_SNARE);
}

void DevilsSnare::Update() {
    Monster::Update();
    if (timer == 0) {
        poisonNeedleNumber = 5;
        timer = 20;
    }

    if (poisonNeedleNumber > 0) {
        PoisonNeedleStrike();
    }
    timer--;
}

void DevilsSnare::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void DevilsSnare::AutoMation() {
}

void DevilsSnare::InitializeWeapon() {
    this->SetWeapon(new UfoWeapon(5));
}

void DevilsSnare::PoisonNeedleStrike() {
    if (poisonNeedleCoolDown == 0) {
        Vec rotation{1.0, 1.0};

        for (int i = 0; i < 18; ++i) {
            Bullet* bullet = static_cast<RedRectangleBullet*>(projectilePool->
                Acquire(ProjectileType::RED_RECTANGLE_BULLET));
            bullet->SetSpeed(rotation, 5);
            bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
            bullet->SetDamage(3);
            bullet->AddTag(Tag::MONSTER_ATTACK);
            bullet->RemoveTag(Tag::PLAYER_ATTACK);
            bullet->SetPoison(true);
            objectManager->AddObject(bullet);
            rotation.Rotate(-0.35);
        }

        poisonNeedleCoolDown = 5;
        poisonNeedleNumber--;
    }
    poisonNeedleCoolDown--;
}
