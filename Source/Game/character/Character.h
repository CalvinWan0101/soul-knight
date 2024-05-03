#pragma once
#include "../utils/object/GeneralObject.h"
#include "../weapon/Weapon.h"

class Character : public GeneralObject {
public:
    Character();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;

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
