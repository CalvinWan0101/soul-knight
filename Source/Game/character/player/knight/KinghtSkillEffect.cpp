#include "stdafx.h"
#include "KinghtSkillEffect.h"

#include "Knight.h"

KinghtSkillEffect::KinghtSkillEffect(Point* authorPoint) : authorPoint(authorPoint) {
    SetVisible(false);
}

void KinghtSkillEffect::Update() {
    GeneralObject::Update();
    this->position = *authorPoint;
}


void KinghtSkillEffect::LoadResources() {
    AddAnimation({"Resources/player/knight/skill/1.bmp",
    "Resources/player/knight/skill/2.bmp",
    "Resources/player/knight/skill/3.bmp",
    "Resources/player/knight/skill/4.bmp",
    "Resources/player/knight/skill/5.bmp",
    "Resources/player/knight/skill/6.bmp"}, RGB(255,255,255), 100, false);
}
