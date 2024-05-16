#include "stdafx.h"
#include "PlayerState.h"

#include "../manager/ObjectManager.h"
#include "../utils/draw/Draw.h"

namespace game_framework {
    class Draw;
}

PlayerState::PlayerState() :
HpBar(200, 20, RGB(77,42,5), RGB(226,55,44), Point(30,30)),
MpBar(200, 20, RGB(77,42,5), RGB(55,117,202), Point(30,60)),
ShildBar(200, 20, RGB(77,42,5), RGB(133,147,138), Point(30,90)),
player(nullptr){
}

void PlayerState::Show() {
    if (!player) {
        player = ObjectManager::Instance()->GetPlayer();
    }
    else {
        HpBar.Show(player->GetHP(), player->GetMaxHP());
        MpBar.Show(player->GetMP(), player->GetMaxMP());
        ShildBar.Show(player->GetShield(), player->GetShield());
    }
}


