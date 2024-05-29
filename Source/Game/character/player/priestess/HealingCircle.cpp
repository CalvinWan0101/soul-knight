#include "stdafx.h"
#include "HealingCircle.h"

#include "../../Player.h"

HealingCircle::HealingCircle() : aliveTime(85), isHealing(true) {
}

void HealingCircle::Start() {
    GeneralObject::Start();
}

void HealingCircle::Update() {
    GeneralObject::Update();
    if (aliveTime == 85 || aliveTime == 45 || aliveTime == 5) {
        isHealing = true;
    }
    else {
        isHealing = false;
    }
    if (aliveTime == 0) {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    aliveTime--;
}

void HealingCircle::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        if (isHealing) {
            dynamic_cast<Player*>(gameObject)->Healing(1);
        }
    }
}

void HealingCircle::LoadResources() {
    AddAnimation({"Resources/player/priestess/skill/priestess_skill_effect.bmp"}, RGB(0,0,0), 1000, false);
}
