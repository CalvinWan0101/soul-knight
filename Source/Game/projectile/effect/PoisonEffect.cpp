#include "stdafx.h"
#include "PoisonEffect.h"

#include "../../character/Character.h"
#include "../../utils/draw/Draw.h"

PoisonEffect::PoisonEffect(Type author) : size(0), maxAliveTime(275) {
    aliveTime = maxAliveTime;
    this->type = author;
}

void PoisonEffect::Start() {
    InvisibleObject::Start();
}

void PoisonEffect::Update() {
    InvisibleObject::Update();
    if (maxAliveTime - aliveTime < maxSize / 2) {
        size += 2;
    }
    if (aliveTime < maxSize / 2) {
        size -= 2;
    }
    if (aliveTime == 0) {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    aliveTime--;
    SetHitBox(2 * size, 2 * size);
}

void PoisonEffect::Show(Point screenPositoin) {
    InvisibleObject::Show(screenPositoin);
    double screenX = this->position.GetX() - screenPositoin.GetX();
    double screenY = this->position.GetY() - screenPositoin.GetY();
    COLORREF color = (type == MONSTER_PURPLE ? RGB(118,50,152) : RGB(81,123,40));
    game_framework::Draw::Instance()->Ellipse(
            Point(screenX - size, screenY - size),
            Point(screenX + size, screenY + size),
            color,
            100
        );
}

void PoisonEffect::Collision(GameObject* gameObject) {
    if ((type == PLAYER && gameObject->HasTag(Tag::MONSTER)) ||
        ((type == MONSTER_GREEN || type == MONSTER_PURPLE) && gameObject->HasTag(Tag::PLAYER))) {
        Character* character = dynamic_cast<Character*>(gameObject);
        if ((character->GetPosition() - this->position).GetLength() < size) {
            character->Poisoned(static_cast<double>(type));
        }
    }
}
