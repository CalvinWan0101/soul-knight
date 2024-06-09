#pragma once
#include "../../../Monster.h"
#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"

class DevilsSnareSkill;

class DevilsSnare : public Monster {
public:
    DevilsSnare(double level);
    ~DevilsSnare();
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;

private:
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    ObjectManager* objectManager = ObjectManager::Instance();
    bool isAngry = false;
    int timer;
    DevilsSnareSkill* skill1;
    DevilsSnareSkill* skill2;
    DevilsSnareSkill* skill3;
};
