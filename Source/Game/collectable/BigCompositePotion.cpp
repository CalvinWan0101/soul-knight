#include "stdafx.h"
#include "BigCompositePotion.h"

BigCompositePotion::BigCompositePotion() {
    SetInteractiveText("Big Composite Potion", InteractiveText::EPIC);
}

void BigCompositePotion::Start() {
    Collectable::Start();
}

void BigCompositePotion::Update() {
    Collectable::Update();
}

void BigCompositePotion::LoadResources() {
    AddAnimation({"Resources/collectable/big_composite_potion.bmp"}, RGB(255,255,255), 1000, false);
}

void BigCompositePotion::Interactive(Player* player) {
    player->Healing(2);
    player->RecoverMP(75);
    AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}