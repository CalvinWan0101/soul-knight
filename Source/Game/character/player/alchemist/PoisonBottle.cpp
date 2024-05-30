#include "stdafx.h"
#include "PoisonBottle.h"

#include "../../Monster.h"
#include "../../../manager/ObjectManager.h"
#include "../../../projectile/effect/PoisonEffect.h"

PoisonBottle::PoisonBottle() {
}

void PoisonBottle::Start() {
    GeneralObject::Start();
    SetHitBoxByRatio(0.9, 0.9);
}

void PoisonBottle::Update() {
    GeneralObject::Update();
}

void PoisonBottle::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::MONSTER) && !gameObject->HasTag(Tag::DEAD)) {
        dynamic_cast<Monster*>(gameObject)->Poisoned(5);
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    else if (gameObject->HasTag(Tag::OBSTACLE)) {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void PoisonBottle::OnRemove() {
    PoisonEffect* poisonEffect = new PoisonEffect(PoisonEffect::PLAYER);
    poisonEffect->SetPosition(this->position);
    ObjectManager::Instance()->AddObject(poisonEffect);
}

void PoisonBottle::LoadResources() {
    AddAnimation({"Resources/player/alchemist/skill/poison_bottle.bmp"},RGB(255,255,255),1000,false);
}


