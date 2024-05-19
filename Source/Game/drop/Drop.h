#pragma once
#include "DropType.h"
#include "../character/Player.h"
#include "../utils/PlayerAlertable.h"
#include "../utils/object/GeneralObject.h"

class Drop : public GeneralObject, public PlayerAlertable{
public:
    Drop();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
    void EnterPlayerAlertRange(Player* player) override;
    DropType GetDropType();
protected:
    void SetDropType(DropType type);
private:
    Player* player;
    DropType dropType;
};
