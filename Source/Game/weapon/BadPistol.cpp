#include "stdafx.h"
#include "BadPistol.h"

BadPistol::BadPistol()
{
}

void BadPistol::Start()
{
    vector<string> filepaths;
    for (int i = 0; i <= 360; i += 3)
    {
        filepaths.push_back("Resources/weapon/bad_pistol/" + to_string(i) + ".bmp");
    }
    SetImages(filepaths, RGB(255, 255, 255));
    point.SetPoint(30, 0);
}

void BadPistol::Update()
{
    SetFrameIndexOfBitmap(rotation.GetRadian());
}

void BadPistol::Attack()
{
}
