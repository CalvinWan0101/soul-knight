#include "stdafx.h"
#include "once_animation_object.h"

OnceAnimationObject::OnceAnimationObject() {
    isAnimationStart = false;
    isAnimationFinished = false;
}

OnceAnimationObject::~OnceAnimationObject() {
}

void OnceAnimationObject::Start() {
    GameObject::Start();
}

void OnceAnimationObject::Update() {
    GameObject::Update();
}

void OnceAnimationObject::Show(Point screenPositoin) {
    double screenX = this->position.GetX() - screenPositoin.GetX();
    double screenY = this->position.GetY() - screenPositoin.GetY();
    if (!isAnimationStart) {
        isAnimationStart = true;
        cMovingBitmap.ToggleAnimation();
    }
    if (cMovingBitmap.IsAnimationDone()) {
        isAnimationFinished = true;
    }
    
    cMovingBitmap.SetTopLeft(static_cast<int>(screenX - centerOffset.GetX()),
                                static_cast<int>(screenY - centerOffset.GetY()));
    cMovingBitmap.ShowBitmap();
}

void OnceAnimationObject::SetHitBoxByRatio(double heightRatio, double widthRatio) {
    hitBox.SetHeight(static_cast<double>(cMovingBitmap.GetHeight()) * heightRatio);
    hitBox.SetWidth(static_cast<double>(cMovingBitmap.GetWidth()) * widthRatio);
}

void OnceAnimationObject::SetAnimation(vector<string> filePaths, int delay, COLORREF color) {
    cMovingBitmap.LoadBitmapByString(filePaths, color);
    cMovingBitmap.SetAnimation(delay, true);
}

void OnceAnimationObject::SetCenter() {
    this->centerOffset.SetVec(cMovingBitmap.GetWidth() / 2, cMovingBitmap.GetHeight() / 2);
}



