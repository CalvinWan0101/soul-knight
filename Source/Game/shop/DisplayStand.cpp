#include "stdafx.h"
#include "DisplayStand.h"

#include "../collectable/PotionFactory.h"
#include "../manager/ObjectManager.h"
#include "../utils/Rand.h"
#include "../weapon/WeaponFactory.h"

DisplayStand::DisplayStand(int level, int stage) : product(nullptr), level(level), stage(stage), price(0) {
}

void DisplayStand::Start() {
    GeneralObject::Start();
    SetHitBoxByRatio(1,1);
    price = level * 20 + Rand::Instance()->Get(stage * -3, stage * 3);
    if (Rand::Instance()->Get(0,1) == 0) {
        int potionId = Rand::Instance()->Get(0, static_cast<int>(PotionFactory::PotionType::Count) - 1);
        product = PotionFactory::Create(static_cast<PotionFactory::PotionType>(potionId));
    }
    else {
        int weaponId = Rand::Instance()->Get(0, WeaponFactory::Name::Count - 1);
        product = WeaponFactory::Create(static_cast<WeaponFactory::Name>(weaponId));
        price *= 2;
    }
    product->SetPosition(this->position+ Point(0,1));
    AddFrontChild(product);
    SetInteractiveText(std::to_string(price), InteractiveText::LEGENDARY);
}

void DisplayStand::LoadResources() {
    AddAnimation({"Resources/shop/display_stand.bmp"}, RGB(255,255,255), 1000, false);
}

void DisplayStand::Interactive(Player* player) {
    if (product) {
        if (ObjectManager::Instance()->SpendMoney(price)) {
            RemoveTag(Tag::INTERACTABLE);
            RemoveFrontChile(product);
            ObjectManager::Instance()->AddObject(product);
            product = nullptr;
        }
    }
}


