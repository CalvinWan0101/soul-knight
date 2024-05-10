#include "stdafx.h"
#include "CharacterAffect.h"

void CharacterAffect::Start() {
    GeneralObject::Start();
}

void CharacterAffect::Update() {
    GeneralObject::Update();
}

void CharacterAffect::SetAnimationIndex(int index) {
    this->index = index;
}