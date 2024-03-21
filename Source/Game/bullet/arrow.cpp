#include "stdafx.h"
#include "arrow.h"

Arrow::Arrow()
{
    
}

void Arrow::Start()
{
    vector<string> filepaths;
    for (int i = 0; i <= 360; i += 3)
    {
        filepaths.push_back("Resources/weapon/bad_pistol/" + to_string(i) + ".bmp");
    }
    SetImages(filepaths, RGB(255, 255, 255));
}

void Arrow::Update()
{
    SetRotation(& speed);
    SetFrameIndexOfBitmap(rotation.GetRadian());
}


