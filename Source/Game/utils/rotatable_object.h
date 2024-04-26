﻿#pragma once
#pragma warning(disable: 4244)

#include <string>
#include <vector>

#include "general_object.h"
#include "vec.h"

class RotatableObject : public GeneralObject {
public:
    RotatableObject();
    void Start() override;
    void Update() override;
    void Rotate(double radian);
    void SetRotation(Vec* radian);
    void SetRotation(double radian);
    Vec GetRotation() const;

protected:
    Vec rotation;
    void SetImages(string filePath, int index, COLORREF color);
    void SetFrameIndexOfBitmap(double radian);
};
