#pragma once
#include "GameObject.h"

class OnceAnimationObject : public  GameObject{
public:
    OnceAnimationObject();
    ~OnceAnimationObject() override;
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void OnRemove() override;

    void SetHitBoxByRatio(double heightRatio, double widthRatio) override;


protected:
    bool isAnimationFinished;
    void SetAnimation(vector<string> filePaths, int delay , COLORREF color);
    void SetCenter() override;
private:
    bool isAnimationStart;
    game_framework::CMovingBitmap cMovingBitmap;
};
