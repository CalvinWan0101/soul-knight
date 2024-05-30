#pragma once
#include "../../../utils/object/GeneralObject.h"

class PoisonBottle : public GeneralObject{
public:
    PoisonBottle();
    void Start() override;
    void Update() override;
    
    void Collision(GameObject* gameObject) override;
    void OnRemove() override;
    void LoadResources() override;
};
