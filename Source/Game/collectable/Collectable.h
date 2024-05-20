#pragma once
#include "../character/Player.h"
#include "../utils/object/GeneralObject.h"

class Collectable : public  GeneralObject{
public:
    Collectable();
    void Start() override;
    void Update() override;

    virtual void Collect(Player* player) = 0;
};
