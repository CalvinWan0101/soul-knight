#include "stdafx.h"
#include "BadPistol.h"

BadPistol::BadPistol()
{
}

void BadPistol::Start()
{
    this->AddAnimation({
                       "resources/weapon/bad_pistol/0.bmp",
                       "resources/weapon/bad_pistol/30.bmp",
                       "resources/weapon/bad_pistol/60.bmp",
                       "resources/weapon/bad_pistol/90.bmp",
                       "resources/weapon/bad_pistol/120.bmp",
                       "resources/weapon/bad_pistol/150.bmp",
                       "resources/weapon/bad_pistol/180.bmp",
                       "resources/weapon/bad_pistol/210.bmp",
                       "resources/weapon/bad_pistol/240.bmp",
                       "resources/weapon/bad_pistol/270.bmp",
                       "resources/weapon/bad_pistol/300.bmp",
                       "resources/weapon/bad_pistol/330.bmp",
                       "resources/weapon/bad_pistol/360.bmp"
                   }, RGB(255, 255, 255), 5, false);
    this->point.SetPoint(30, 30);
}

void BadPistol::Update()
{
}

void BadPistol::Attack()
{
}
