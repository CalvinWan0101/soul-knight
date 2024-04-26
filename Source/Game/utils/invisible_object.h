#pragma once
#include "general_object.h"

class InvisibleObject : public GameObject{
public:
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void Collision(GameObject* gameObject) override;

    virtual void SetHitBoxByRatio(double heightRatio, double widthRatio) override;

protected:
    virtual void SetCenter() override;
};
