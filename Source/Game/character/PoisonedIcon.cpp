#include "stdafx.h"
#include "PoisonedIcon.h"

PoisonedIcon::PoisonedIcon() {
    visible = false;
}

void PoisonedIcon::LoadResources() {
    AddAnimation({"Resources/affect/poisoned_icon.bmp"},RGB(255,255,255),1000,false);
}