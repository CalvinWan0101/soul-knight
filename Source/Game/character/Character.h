#pragma once
#include "PoisonedIcon.h"
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
    virtual void Injuried(double damage) = 0;
    void Poisoned(double poisonDamage);

protected:
    double hp;
    double maxHp;
    
    Vec vision;
    Weapon* weapon1;
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
    PoisonedIcon* poisonedIcon;
    struct Poison {
        double damage;
        int counter;
        int damageRemainingTimes;
        const int damageInterval = 50;
    } poison;
    void CheckState();
    void CheckFace();
};
