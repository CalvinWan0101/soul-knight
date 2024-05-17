#pragma once
#include "../character/Player.h"
#include "../utils/PlayerAlertable.h"
#include "../utils/object/GeneralObject.h"

class MagnetizedDrop : public GeneralObject, public PlayerAlertable{
public:
    MagnetizedDrop();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
    void EnterPlayerAlertRange(Player* player) override;
private:
    Player* player;
};
