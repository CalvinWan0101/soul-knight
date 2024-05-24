#pragma once
#include "../utils/object/GeneralObject.h"
#include "Character.h"

class Player : public Character {
public:
    Player();
    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;

    void Attack() override;
    void Injuried(double damage) override;
    int GetMP();
    int GetMaxMP();
    void RecoverMP(int value);
    void Healing(int value);
    double GetShield();
    double GetMaxShield();
    HitBox& GetAlertRange();

    void SetVision(Vec vision);
    void ChangeWeapon(Weapon* newWeapon);
    void SwitchWeapon();

    void SetInteractive(bool interactive);

protected:
    int mp;
    int maxMp;
    double shield;
    double maxShild;
    int damageCooldownCounter;
    int damageCooldownFrameCD;
    int damageEffectCounter;
    int shieldRecoverCooldownCounter;
    int shieldRecoverCooldownFrameCD;
    HitBox alertRange;
    Weapon* weapon2;

private:
    bool interactive;
    void SetAlertRange(double height, double witdth);
    void CalculateDamageCooldownCounter();
    void CalculateShieldRecoverCounter();
    void DamageEffect();
};
