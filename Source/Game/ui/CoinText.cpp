#include "stdafx.h"
#include "CoinText.h"

#include "../manager/ObjectManager.h"
#include "../utils/draw/Draw.h"

CoinText::CoinText(Point point) : point(point) {
}

void CoinText::Start() {
    coinIcon.LoadBitmapByString({"Resources/ui/player_state/coin_icon.bmp"},RGB(255,255,255));
    coinIcon.SetTopLeft(point.GetX(), point.GetY() + 5);
}


void CoinText::Show() {
    coinIcon.ShowBitmap();
    string coinNumber = "X" + std::to_string(ObjectManager::Instance()->GetMoney());
    game_framework::Draw::Instance()->Text(point + Point(20, 8), 12, RGB(255,255,255),coinNumber, "MS Gothic");
}


