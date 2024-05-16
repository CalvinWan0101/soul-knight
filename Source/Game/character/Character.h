#pragma once
#include "../utils/object/GeneralObject.h"
#include "../weapon/Weapon.h"

class Character : public GeneralObject {
public:
    Character();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;

    double GetHP();
    double GetMaxHP();
    virtual void Attack();
    void BeAttacked(double damage);

protected:
    double hp;
    double maxHp;
    
    Vec vision;
    Weapon* weapon;
    double weaponOffsetX;
    double weaponOffsetY;
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
private:
    void CheckState();
    void CheckFace();
};
