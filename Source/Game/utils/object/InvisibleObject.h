#pragma once
#include "GeneralObject.h"

class InvisibleObject : public GameObject{
public:
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void Show(Point screenPositoin) override;
    void OnRemove() override;

    void SetHitBoxByRatio(double heightRatio, double widthRatio) override;

protected:
    void SetCenter() override;
};
