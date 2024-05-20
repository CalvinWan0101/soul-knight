#include "stdafx.h"
#include "MpPotion.h"

MpPotion::MpPotion() {
    SetInteractiveText("MP Potion", InteractiveText::RARE);
}

void MpPotion::Start() {
    Collectable::Start();
}

void MpPotion::Update() {
    Collectable::Update();
}

void MpPotion::LoadResources() {
    AddAnimation({"Resources/collectable/mp_potion.bmp"}, RGB(255,255,255), 1000, false);
}

void MpPotion::Collect(Player* player) {
    player->RecoverMP(80);
    AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}
