#pragma once
#include "..\..\utils\general_object.h"
#include "../../character/character.h"

class Player : public Character {
public:
    Player();
    void Start() override;
    void Update() override;
    void Collision(GeneralObject* generalObject) override;

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
    HitBox alertRange;
private:
    bool interactive;
    void SetAlertRange(double height, double witdth);
    
};
