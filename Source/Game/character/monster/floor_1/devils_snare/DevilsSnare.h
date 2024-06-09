#pragma once
#include "../../../Monster.h"
#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "skill/DevilsSnareSkill2.h"

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
    DevilsSnareSkill2* skill2;
};
