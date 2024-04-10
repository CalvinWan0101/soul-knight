#pragma once
#include "../../utils/game_object.h"
#include "../../character/character.h"

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
    HitBox GetAlertRange();

    void SetVision(Vec vision);
    void ChangeWeapon(Weapon* newWeapon);

protected:
    int mp;
    int maxMp;
    int shield;
    int maxShild;
    HitBox alertRange;
private:
    void SetAlertRange(double height, double witdth);
    
};
