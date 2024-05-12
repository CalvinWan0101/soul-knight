#include "stdafx.h"
#include "FakeWeapon.h"

void FakeWeapon::Start() {
}

void FakeWeapon::Update() {
}

void FakeWeapon::LoadResources() {
}

void FakeWeapon::Show(Point screenPositoin) {
}

void FakeWeapon::Attack() {
}

void FakeWeapon::Aim(Vec* direction) {
}

Weapon* FakeWeapon::Copy() {
    return new FakeWeapon();
}
