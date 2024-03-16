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
    i += 0.05;
    if(i>6.28)
    {
        i = 0;
    }
    SetFrameIndexOfBitmap(i);
}

void BadPistol::Attack()
{
}
