#pragma once
#pragma warning(disable: 4244)

#include <string>
#include <vector>

#include "game_object.h"
#include "vec.h"

class RotatableObject : public game_framework::GameObject {
public:
    RotatableObject();
    void Start() override = 0;
    void Update() override = 0;
    void Rotate(double radian);
    void SetRotation(Vec* radian);
    Vec GetRotation() const;

protected:
    Vec rotation;
    void SetImages(string filePath, int index, COLORREF color);
    void SetFrameIndexOfBitmap(double radian);
};
