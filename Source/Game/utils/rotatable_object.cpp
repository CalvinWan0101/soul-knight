#include "stdafx.h"
#include "rotatable_object.h"
// #include "../mygame.h"

#include <string>
#include <vector>

#define PI 3.14159265359

RotatableObject::RotatableObject() {
    rotation = Vec(1, 0);
}

void RotatableObject::Rotate(double radian) {
    rotation.Rotate(radian);
    SetFrameIndexOfBitmap(rotation.GetRadian());
}

void RotatableObject::SetRotation(Vec* radian) {
    rotation = Vec(radian);
    SetFrameIndexOfBitmap(rotation.GetRadian());
}

Vec RotatableObject::GetRotation() const {
    return rotation;
}

void RotatableObject::SetImages(string filePath, int index, COLORREF color) {
    vector<string> filepaths;
    for (int i = 0; i <= 360; i += index) {
        filepaths.push_back(filePath + to_string(i) + ".bmp");
    }
    game_framework::CMovingBitmap cMovingBitmap = game_framework::CMovingBitmap();
    cMovingBitmap.LoadBitmapByString(filepaths, color);
    cMovingBitmaps.push_back(cMovingBitmap);
}

void RotatableObject::SetFrameIndexOfBitmap(double radian) {
    cMovingBitmaps[0].SetFrameIndexOfBitmap(static_cast<int>((radian / (2 * PI) ) * static_cast<double>(cMovingBitmaps[0].GetFrameSizeOfBitmap())));
}
