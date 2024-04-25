#include "stdafx.h"
#include "knife.h"
#include "../character/player/player.h"


Knife::Knife() {
}

Knife::Knife(Point point) : Weapon(point) {
}


void Knife::Start() {
    Weapon::Start();
}

void Knife::Update() {
    Weapon::Update();
}
