#include "stdafx.h"
#include "RotatableObject.h"
// #include "../mygame.h"

#include <string>
#include <vector>

#define PI 3.14159265359

RotatableObject::RotatableObject(): rotation(Vec(1, 0)) {
}

void RotatableObject::Start() {
    GameObject::Start();
}

void RotatableObject::Update() {
    GameObject::Update();
}

void RotatableObject::Show(Point screenPositoin) {
    if (!visible)
        return;
    SetFrameIndexOfBitmap(rotation.GetRadian());
    double screenX = this->position.GetX() - screenPositoin.GetX() + showOffset.GetX();
    double screenY = this->position.GetY() - screenPositoin.GetY() + showOffset.GetY();
    cMovingBitmap.SetTopLeft(static_cast<int>(screenX - centerOffset.GetX()),
                             static_cast<int>(screenY - centerOffset.GetY()));
    cMovingBitmap.ShowBitmap();
    showOffset.SetX(0);
    showOffset.SetY(0);
}

void RotatableObject::OnRemove() {
}

void RotatableObject::Rotate(double radian) {
    rotation.Rotate(radian);
}

void RotatableObject::SetRotation(Vec* radian) {
    rotation = Vec(radian);
}

void RotatableObject::SetRotation(double radian) {
    rotation.Rotate(radian - rotation.GetRadian());
}

Vec RotatableObject::GetRotation() const {
    return rotation;
}

void RotatableObject::SetHitBoxByRatio(double heightRatio, double widthRatio) {
    hitBox.SetHeight(static_cast<double>(cMovingBitmap.GetHeight()) * heightRatio);
    hitBox.SetWidth(static_cast<double>(cMovingBitmap.GetWidth()) * widthRatio);
}

void RotatableObject::SetImages(string filePath, int index, COLORREF color) {
    vector<string> filepaths;
    for (int i = 0; i <= 360; i += index) {
        filepaths.push_back(filePath + to_string(i) + ".bmp");
    }
    cMovingBitmap = game_framework::CMovingBitmap();
    cMovingBitmap.LoadBitmapByString(filepaths, color);
}

void RotatableObject::SetFrameIndexOfBitmap(double radian) {
    cMovingBitmap.SetFrameIndexOfBitmap(
        static_cast<int>((radian / (2 * PI)) * static_cast<double>(cMovingBitmap.GetFrameSizeOfBitmap())));
}

void RotatableObject::SetCenter() {
    this->centerOffset.SetVec(cMovingBitmap.GetWidth() / 2, cMovingBitmap.GetHeight() / 2);
}
