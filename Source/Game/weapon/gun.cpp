#include "stdafx.h"
#include "gun.h"

Gun::Gun() {
}

Gun::Gun(Point point) : Weapon(point) {
}

void Gun::Start() {
    Weapon::Start();   
}

void Gun::Update() {
    Weapon::Update();
}

