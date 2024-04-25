#pragma once
#include "..\utils\general_object.h"
#include "../weapon/weapon.h"

class Character : public game_framework::GeneralObject {
public:
    Character();
    void Start() override;
    void Update() override;
    void Collision(GeneralObject* generalObject) override;

    int GetHP();
    int GetMaxHP();
    void Attack();
    void BeAttacked(int damage);

protected:
    int hp;
    int maxHp;
    
    Vec vision;
    Weapon* weapon;
    double weaponOffsetX;
    double weaponOffsetY;
private:
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
    void CheckState();
    void CheckFace();
};
