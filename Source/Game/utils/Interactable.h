#pragma once


class Player;
class Interactable {
public:
    virtual void Interactive(Player* player) = 0;
};