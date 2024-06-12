#include "stdafx.h"
#include "AlienRedLightsaber.h"

#include "../../../../weapon/melee_weapon/RedLightsaber.h"

AlienRedLightsaber::AlienRedLightsaber(double level) : Alien(level, true) {
}

void AlienRedLightsaber::Start() {
    Alien::Start();
    SetMonsterType(MonsterType::ALIEN_RED_LIGHTSABER);
}

void AlienRedLightsaber::InitializeWeapon() {
    this->SetWeapon(new RedLightsaber(5));
}
