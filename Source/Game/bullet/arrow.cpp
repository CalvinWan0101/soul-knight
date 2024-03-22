#include "stdafx.h"
#include "arrow.h"

Arrow::Arrow() {
}

void Arrow::Start() {
    SetImages("Resources/bullet/bad_bullet/", 3, RGB(255, 255, 255));
}

void Arrow::Update() {
    SetRotation(&speed);
}
