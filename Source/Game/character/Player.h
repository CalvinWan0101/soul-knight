#pragma once
#include "../utils/object/GeneralObject.h"
#include "Character.h"

class Player : public Character {
public:
    Player();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;

    int GetMP();
    int GetMaxMP();
    int GetShield();
    int GetMaxShield();
    HitBox& GetAlertRange();

    void SetVision(Vec vision);
    void ChangeWeapon(Weapon* newWeapon);

    void SetInteractive(bool interactive);

protected:
    int mp;
    int maxMp;
    int shield;
    int maxShild;
    int damageCooldownCounter;
    HitBox alertRange;

private:
    bool interactive;
    void SetAlertRange(double height, double witdth);
};
