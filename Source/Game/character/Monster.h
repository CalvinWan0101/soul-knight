#pragma once
#include "Character.h"

class Player;

class Monster : public Character {
public:
    Monster(double level);
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;
    virtual void AutoMation() = 0;
    void EnterPlayerAlertRange(Player* player);

    void SetWeapon(Weapon* weapon);

protected:
    double maxSpeed;
    double level;

private:
    Player* player = nullptr;
};
