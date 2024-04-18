#pragma once
#include "../utils/game_object.h"
#include "../weapon/weapon.h"

class Character : public game_framework::GameObject {
public:
    Character();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;

    int GetHP();
    int GetMaxHP();
    void Attack();
    void BeAttacked(int damage);
    bool IsDead();

protected:
    void CheckState();
    int hp;
    int maxHp;

    enum Face {
        RIGHT,
        LEFT
    };

    enum State {
        IDLE,
        RUN,
        DEAD,
        READY
    };

    Face face;
    State state;
    Vec vision;
    Weapon* weapon;
    double weaponOffsetX;
    double weaponOffsetY;
};
