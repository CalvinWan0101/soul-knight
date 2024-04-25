#pragma once
#include "../character.h"

class Player;

class Monster : public Character {
public:
    Monster();
    void Start() override;
    void Update() override;
    void Collision(GeneralObject* generalObject) override;
    void EnterPlayerAlertRange(Player* player);

    void SetWeapon(Weapon* weapon);

protected:
    double maxSpeed;
private:
    Player* player = nullptr;
};
