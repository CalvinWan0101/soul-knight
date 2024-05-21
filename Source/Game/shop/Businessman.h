#pragma once
#include "../utils/Interactable.h"
#include "../utils/object/GeneralObject.h"

class Businessman : public GeneralObject, public Interactable{
public:
    Businessman(int level, int stage);
    void Start() override;
    void LoadResources() override;

    void Interactive(Player* player) override;
private:
    int level;
    int stage;
};
