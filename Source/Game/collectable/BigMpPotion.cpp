#include "stdafx.h"
#include "BigMpPotion.h"

BigMpPotion::BigMpPotion() {
    SetInteractiveText("Big Mp Potion", InteractiveText::RARE);
}

void BigMpPotion::Start() {
    Collectable::Start();
}

void BigMpPotion::Update() {
    Collectable::Update();
}

void BigMpPotion::LoadResources() {
    AddAnimation({"Resources/collectable/big_mp_potion.bmp"}, RGB(255,255,255), 1000, false);
}

void BigMpPotion::Collect(Player* player) {
    player->RecoverMP(150);
    AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}