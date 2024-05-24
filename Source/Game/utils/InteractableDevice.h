#pragma once


class Player;

class InteractableDevice {
public:
    virtual void Interactive(Player* player) = 0;
};
