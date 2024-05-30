#pragma once
#include "../../../utils/object/GeneralObject.h"

class HealingCircle : public GeneralObject{
public:
    HealingCircle();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
    void LoadResources() override;

private:
    int aliveTime;
    bool isHealing;
};
