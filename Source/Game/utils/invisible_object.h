#pragma once
#include "general_object.h"

class InvisibleObject : public GameObject{
public:
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;

    void SetHitBoxByRatio(double heightRatio, double widthRatio) override;

protected:
    void SetCenter() override;
};
