#include "stdafx.h"
#include "PlayerState.h"

#include "../manager/ObjectManager.h"
#include "../utils/draw/Draw.h"

namespace game_framework {
    class Draw;
}

PlayerState::PlayerState(Point point) :
HpBar(180, 20, RGB(77,42,5), RGB(226,55,44), RGB(82,63,43), point + Point(15,20)),
ShildBar(180, 20, RGB(77,42,5), RGB(133,147,138), RGB(82,63,43), point + Point(15,50)),
MpBar(180, 20, RGB(77,42,5), RGB(55,117,202), RGB(82,63,43), point + Point(15,80)),
player(nullptr){
    this->point = point;
}

void PlayerState::Show() {
    if (!player) {
        player = ObjectManager::Instance()->GetPlayer();
    }
    else {
        string hpStr = std::to_string(static_cast<int>(player->GetHP())) + " / " + std::to_string(static_cast<int>(player->GetMaxHP()));
        game_framework::Draw::Instance()->Text(point + Point(15 + 5,20 + 3), 12, RGB(255,255,255), hpStr, "Consolas");
        string shieldStr = std::to_string(static_cast<int>(player->GetShield())) + " / " + std::to_string(static_cast<int>(player->GetMaxShield()));
        game_framework::Draw::Instance()->Text(point + Point(15 + 5,50 + 3), 12, RGB(255,255,255), shieldStr, "Consolas");
        string mpStr = std::to_string(player->GetMP()) + " / " + std::to_string(player->GetMaxMP());
        game_framework::Draw::Instance()->Text(point + Point(15 + 5,80 + 3), 12, RGB(255,255,255), mpStr, "Consolas");
        HpBar.Show(player->GetHP(), player->GetMaxHP());
        ShildBar.Show(player->GetShield(), player->GetMaxShield());
        MpBar.Show(player->GetMP(), player->GetMaxMP());
        game_framework::Draw::Instance()->EmptyRectangle(point, point + Point(210, 120), RGB(30,30, 30), Point(8, 8), 5);
        game_framework::Draw::Instance()->Rectangle(point, point + Point(210, 120), RGB(155,129,102));
    }
}


