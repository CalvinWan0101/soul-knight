#include "stdafx.h"
#include "PoisonSpider.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../projectile/effect/PoisonEffect.h"

PoisonSpider::PoisonSpider(double level) : BaseSpider((level)) {
}

void PoisonSpider::Start() {
    BaseSpider::Start();
    SetMonsterType(MonsterType::POISON_SPIDER);
}

void PoisonSpider::LoadResources() {
    this->AddAnimation({
                       "resources/monster/floor_2/poison_spider/idle/1.bmp",
                       "resources/monster/floor_2/poison_spider/idle/2.bmp"
                   }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/poison_spider/idle/flip_1.bmp",
                           "resources/monster/floor_2/poison_spider/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/poison_spider/run/1.bmp",
                           "resources/monster/floor_2/poison_spider/run/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/poison_spider/run/flip_1.bmp",
                           "resources/monster/floor_2/poison_spider/run/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/poison_spider/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/poison_spider/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void PoisonSpider::OnDead() {
    BaseSpider::OnDead();
    PoisonEffect* poisonEffect = new PoisonEffect(PoisonEffect::MONSTER_GREEN);
    poisonEffect->SetPosition(this->position);
    ObjectManager::Instance()->AddObject(poisonEffect);
}


