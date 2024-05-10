#pragma once
#include "Character.h"

class Player;

class Monster : public Character {
public:
    Monster(double level);
    virtual void Start() override;
    virtual void Update() override;
    virtual void Collision(GameObject* gameObject) override;
    virtual void AutoMation() = 0;
    void EnterPlayerAlertRange(Player* player);

    void SetWeapon(Weapon* weapon);

protected:
    double maxSpeed;
    double level;
private:
    Player* player = nullptr;
};
