#include "stdafx.h"
#include "HealingPotion.h"

HealingPotion::HealingPotion() {
    SetInteractiveText("Healing Potion", InteractiveText::MYTHIC);
}

void HealingPotion::Start() {
    Collectable::Start();
}

void HealingPotion::Update() {
    Collectable::Update();
}

void HealingPotion::LoadResources() {
    AddAnimation({"Resources/collectable/healing_potion.bmp"}, RGB(255,255,255), 1000, false);
}

void HealingPotion::Collect(Player* player) {
    player->Healing(2);
    AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}
