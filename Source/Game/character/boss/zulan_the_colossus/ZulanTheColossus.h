#pragma once
#include "../../Monster.h"
#include "../../../ui/Bar.h"
#include "skill/BossSkill.h"

class FloatingGun;

class ZulanTheColossus : public Monster {
public:
    ZulanTheColossus();
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void OnDead() override;
    void LoadResources() override;
    void Collision(GameObject* gameObject) override;
    void AutoMationMove() override;
    void AutoMation() override;
    void InitializeWeapon() override;
private:
    bool isAngry;
    bool collideOnObstacle;
    bool CheckAngry();
    void CheckState() override;
    Bar hpBar;
    vector<FloatingGun*> floatingGuns;
    BossSkill* skill;
};
