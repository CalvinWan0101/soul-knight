#include "stdafx.h"
#include "ZulanTheColossus.h"

#include "FloatingGun.h"
#include "../../../drop/DropType.h"
#include "../../../manager/ObjectManager.h"
#include "../../../pool/DropPool.h"
#include "../../../utils/Rand.h"
#include "../../../weapon/melee_weapon/FakeWeapon.h"
#include "../../../drop/Drop.h"
#include "skill/ZulanAngrySkill.h"
#include "skill/ZulanFloatingGunSkill1.h"
#include "skill/ZulanFloatingGunSkill2.h"
#include "skill/ZulanSkill1.h"
#include "skill/ZulanSkill2.h"
#include "skill/ZulanSkill3.h"
#include "skill/ZulanSkill4.h"

ZulanTheColossus::ZulanTheColossus() :
Monster(1),
isAngry(false),
collideOnObstacle(false),
hpBar(500, 20, RGB(77,0,124), RGB(226,55,44), RGB(17,0,64), Point(280, 30)),
normalSkill(nullptr),
floatingGunSkill(nullptr){
    skillColdDown = 100;
    normalSkillColdDownCounter = Rand::Instance()->Get(skillColdDown, skillColdDown * 2);
    floatingGunSkillColdDownCounter = Rand::Instance()->Get(skillColdDown, skillColdDown * 2);
}

ZulanTheColossus::~ZulanTheColossus()
{
    if (normalSkill)
    {
        delete normalSkill;
    }

    if (floatingGunSkill)
    {
        delete floatingGunSkill;
    }
}


void ZulanTheColossus::Start() {
    Monster::Start();
    // this->skill = new ZulanAngrySkill(this);
    this->maxHp = 883;
    this->maxSpeed = 1;
    this->hp = maxHp;
    SetMonsterType(MonsterType::ZULAN);
    for(int i = 0 ; i < 5 ; i++)
    {
        floatingGuns[i]->SetPosition(this->position);
    }
}

void ZulanTheColossus::Update() {
    Monster::Update();
    SkillControl();
}

void ZulanTheColossus::Show(Point screenPositoin) {
    Monster::Show(screenPositoin);
    hpBar.Show(hp, maxHp);
}

void ZulanTheColossus::SkillControl()
{
    if (CheckAngry())
    {
        skillColdDown = 75;
    }
    
    if (normalSkill)
    {
        if (normalSkill->Update())
        {
            delete normalSkill;
            normalSkill = nullptr;
        }
    }
    else
    {
        normalSkillColdDownCounter--;
        if (normalSkillColdDownCounter == 0)
        {
            RandomNormalSkills();
            normalSkillColdDownCounter = Rand::Instance()->Get(skillColdDown * 2, skillColdDown * 3);
        }
    }

    if (floatingGunSkill)
    {
        if (floatingGunSkill->Update())
        {
            delete floatingGunSkill;
            floatingGunSkill = nullptr;
        }
    }
    else
    {
        floatingGunSkillColdDownCounter--;
        if (floatingGunSkillColdDownCounter == 0)
        {
            RandomFloatingGunSkills();
            floatingGunSkillColdDownCounter = Rand::Instance()->Get(skillColdDown, skillColdDown * 2);
        }
    }
}

void ZulanTheColossus::RandomNormalSkills()
{
    switch(Rand::Instance()->Get(0, CheckAngry() ? 4 : 3))
    {
    case 0:
        this->normalSkill = new ZulanSkill1(this);
        break;
    case 1:
        this->normalSkill = new ZulanSkill2(this);
        break;
    case 2:
        this->normalSkill = new ZulanSkill3(this);
        break;
    case 3:
        this->normalSkill = new ZulanSkill4(this);
        break;
    case 4:
        this->normalSkill = new ZulanAngrySkill(this);
        break;
    default:
        this->normalSkill = nullptr;        
    }
}

void ZulanTheColossus::RandomFloatingGunSkills()
{
    switch(Rand::Instance()->Get(0, 1))
    {
    case 0:
        this->floatingGunSkill = new ZulanFloatingGunSkill1(this);
        break;
    case 1:
        this->floatingGunSkill = new ZulanFloatingGunSkill2(this);
        break;
    default:
        this->floatingGunSkill = nullptr;        
    }
}


void ZulanTheColossus::OnDead() {
    GameObject* drop;
    for (int i = 0; i < Rand::Instance()->Get(10, 30); i++) {
        drop = DropPool::Instance()->Acquire(DropType::COIN);
        drop->SetPosition(
            this->position + Point(Rand::Instance()->Get(-30, 30), Rand::Instance()->Get(-30, 30)));
        ObjectManager::Instance()->AddObject(drop);
    }
    for (int i = 0; i < Rand::Instance()->Get(10, 30); i++) {
        drop = DropPool::Instance()->Acquire(DropType::MAGIC_BALL);
        drop->SetPosition(
            this->position + Point(Rand::Instance()->Get(-30, 30), Rand::Instance()->Get(-30, 30)));
        ObjectManager::Instance()->AddObject(drop);
    }

    for (int i = 0 ; i < 5 ; i++)
    {
        floatingGuns[i]->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void ZulanTheColossus::LoadResources() {
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/normal/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/normal/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/angry/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/angry/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    for(int i = 0 ; i < 5 ; i++)
    {
        FloatingGun* floatingGun = new FloatingGun(this, i); 
        floatingGuns.emplace_back(floatingGun);
        floatingGun->SetPosition(this->position);
        ObjectManager::Instance()->AddObject(floatingGun);
    }
}

void ZulanTheColossus::Collision(GameObject* gameObject)
{
    Monster::Collision(gameObject);
    if (gameObject->HasTag(Tag::OBSTACLE))
    {
        collideOnObstacle = true;
    }
}

void ZulanTheColossus::AutoMationMove()
{
    if (Rand::Instance()->Get(0,99) == 0 || collideOnObstacle)
    {
        collideOnObstacle = false;
        this->speed = Vec(Rand::Instance()->Get(-9,9), Rand::Instance()->Get(-9,9));
        this->speed.SetLength(maxSpeed);
        this->vision = this->speed;
    }
}


void ZulanTheColossus::AutoMation() {
    
}

void ZulanTheColossus::InitializeWeapon() {
    SetWeapon(new FakeWeapon());
}

vector<FloatingGun*> ZulanTheColossus::GetFloatingGuns()
{
    return floatingGuns;
}

bool ZulanTheColossus::CheckAngry() {
    return hp < maxHp / 2;
}

void ZulanTheColossus::CheckState() {
    if (hp <= 0) {
        state = DEAD;
        AddTag(Tag::DEAD);
    }
    else if (!CheckAngry()) {
        state = IDLE;
    }
    else {
        state = RUN;
    }
}





