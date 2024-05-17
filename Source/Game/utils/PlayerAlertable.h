#pragma once

class Player;

class PlayerAlertable {
public:
    virtual void EnterPlayerAlertRange(Player* player) = 0;
};
