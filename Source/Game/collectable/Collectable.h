#pragma once
#include "../character/Player.h"
#include "../utils/InteractableDevice.h"
#include "../utils/object/GeneralObject.h"

class Collectable : public  GeneralObject, public InteractableDevice{
public:
    Collectable();
    void Start() override;
    void Update() override;

    virtual void Interactive(Player* player) override = 0;
};
