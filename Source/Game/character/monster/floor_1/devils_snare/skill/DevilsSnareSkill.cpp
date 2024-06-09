#include "stdafx.h"
#include "DevilsSnareSkill.h"

DevilsSnareSkill::DevilsSnareSkill(Point* position, int bulletCoolDown, int bulletNumber) : position(position),
    bulletCoolDown(bulletCoolDown), bulletNumber(bulletNumber), bulletCoolDownCounter(bulletCoolDown),
    bulletNumberCounter(bulletNumber) {
}

void DevilsSnareSkill::Update() {
    if (bulletNumberCounter == 0) {
        return;
    }
    bulletCoolDownCounter--;
    if (bulletCoolDownCounter == 0) {
        GenerageBullet();
        bulletCoolDownCounter = bulletCoolDown;
        bulletNumberCounter--;
    }
}

void DevilsSnareSkill::Activate() {
    bulletNumberCounter = bulletNumber;
}
