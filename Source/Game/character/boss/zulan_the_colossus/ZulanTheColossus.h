#pragma once
#include "../../Monster.h"
#include "../../../ui/Bar.h"
#include "skill/BossSkill.h"

class FloatingGun;

class ZulanTheColossus : public Monster {
public:
    ZulanTheColossus();
    ~ZulanTheColossus() override;
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void SkillControl();
    void RandomNormalSkills();
    void RandomFloatingGunSkills();
    void OnDead() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;
    
    vector<FloatingGun*> GetFloatingGuns();
private:
    bool isAngry;
    bool CheckAngry();
    void CheckState() override;
    Bar hpBar;
    vector<FloatingGun*> floatingGuns;
    BossSkill* normalSkill;
    BossSkill* floatingGunSkill;
    int normalSkillColdDownCounter;
    int floatingGunSkillColdDownCounter;
    int skillColdDown;
};
