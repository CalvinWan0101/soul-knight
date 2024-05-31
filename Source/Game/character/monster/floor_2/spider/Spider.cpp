#include "stdafx.h"
#include "Spider.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../projectile/shock_wave/BlowUp.h"

Spider::Spider(double level) : BaseSpider(level) {
}

void Spider::Start() {
    BaseSpider::Start();
    SetMonsterType(MonsterType::SPIDER);
}

void Spider::LoadResources() {
    this->AddAnimation({
                       "resources/monster/floor_2/spider/idle/1.bmp",
                       "resources/monster/floor_2/spider/idle/2.bmp"
                   }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/spider/idle/flip_1.bmp",
                           "resources/monster/floor_2/spider/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/spider/run/1.bmp",
                           "resources/monster/floor_2/spider/run/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/spider/run/flip_1.bmp",
                           "resources/monster/floor_2/spider/run/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/spider/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/spider/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void Spider::OnDead() {
    BaseSpider::OnDead();
    BlowUp* blowUp = new BlowUp();
    blowUp->SetPosition(this->position);
    blowUp->SetDamage(5);
    blowUp->AddTag(Tag::MONSTER_ATTACK);
    blowUp->AddTag(Tag::PLAYER_ATTACK);
    ObjectManager::Instance()->AddObject(blowUp);
}


