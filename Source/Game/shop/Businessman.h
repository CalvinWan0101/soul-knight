#pragma once
#include "../utils/InteractableDevice.h"
#include "../utils/object/GeneralObject.h"

class DisplayStand;

class Businessman : public GeneralObject, public InteractableDevice {
public:
    Businessman(int level, int stage);
    ~Businessman();
    void Start() override;
    void LoadResources() override;

    void Interactive(Player* player) override;

private:
    int level;
    int stage;
    std::vector<DisplayStand*> displayStands;
};
