#include "stdafx.h"
#include "SkillCDBar.h"

#include "../config.h"
#include "../manager/ObjectManager.h"

SkillCDBar::SkillCDBar(Point point) :
skillCD(150, 20, RGB(133,147,138),RGB(86,133,61), RGB(63,77,68), point),
player(nullptr),
point(point){
}

void SkillCDBar::Show() {
    if (!player) {
        player = ObjectManager::Instance()->GetPlayer();
    }
    skillCD.Show(player->GetSkillFrameCD() - player->GetSkillCD(), player->GetSkillFrameCD());
}

