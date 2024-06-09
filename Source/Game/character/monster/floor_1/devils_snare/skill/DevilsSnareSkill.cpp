#include "stdafx.h"
#include "DevilsSnareSkill.h"

DevilsSnareSkill::DevilsSnareSkill(Point* position, int bulletCoolDown, int bulletNumber) : position(position),
    bulletCoolDown(bulletCoolDown), bulletNumber(bulletNumber), bulletCoolDownCounter(bulletCoolDown),
    bulletNumberCounter(bulletNumber) {
}

void DevilsSnareSkill::Update() {
    if (bulletNumberCounter > 0) {
        GenerageBullet();
    }
}

void DevilsSnareSkill::Activate() {
    bulletNumberCounter = bulletNumber;
}
