#include "stdafx.h"
#include "bad_pistol.h"

#include "../bullet/arrow.h"
#include "../utils/object_manager.h"

BadPistol::BadPistol() {
}

void BadPistol::Start() {
    vector<string> filepaths;
    for (int i = 0; i <= 360; i += 3) {
        filepaths.push_back("Resources/weapon/bad_pistol/" + to_string(i) + ".bmp");
    }
    SetImages(filepaths, RGB(255, 255, 255));
    // point.SetPoint(30, 0);
}

void BadPistol::Update() {
    SetFrameIndexOfBitmap(rotation.GetRadian());
    Attack();
}

void BadPistol::Attack() {
    Bullet* bullet = new Arrow();
    bullet->SetSpeed(rotation, 10);
    Vec offset = Vec(&rotation, 6);
    ObjectManager::Instance()->AddPlayerBullets(bullet, offset);
}
