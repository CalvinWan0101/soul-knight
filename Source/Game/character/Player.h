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
    int GetSkillFrameCD();
    int GetSkillCD();
    HitBox& GetAlertRange();

    void SetVision(Vec vision);
    void ChangeWeapon(Weapon* newWeapon);
    void SwitchWeapon();

    void UseSkill();

    void SetInteractive(bool interactive);

    void SwitchInvincibleMode();
    void SwitchThroughWallMode();

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

    int skillCounter;
    int skillFrameCD;
    virtual void Skill() = 0;

private:
    bool interactive;
    bool invincible;
    bool throughWall;
    void SetAlertRange(double height, double witdth);
    void CalculateDamageCooldownCounter();
    void CalculateShieldRecoverCounter();
    void DamageEffect();
};
