#pragma once
#include "../utils/Interactable.h"
#include "../utils/object/GeneralObject.h"

class DisplayStand : public GeneralObject, public Interactable {
public:
    DisplayStand(int level, int stage);
    void Start() override;

    void LoadResources() override;
    
    void Interactive(Player* player) override;
private:
    GameObject* product;
    int level;
    int stage;
    int price;
};
