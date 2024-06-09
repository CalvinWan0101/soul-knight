#pragma once
#include "../../../../../manager/ObjectManager.h"
#include "../../../../../pool/ProjectilePool.h"

class DevilsSnareSkill {
public:
    DevilsSnareSkill(Point* position, int bulletCoolDown, int bulletNumber);
    void Update();
    void Activate();

protected:
    ObjectManager* objectManager = ObjectManager::Instance();
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    Point* position;
    const int bulletCoolDown;
    const int bulletNumber;
    int bulletCoolDownCounter;
    int bulletNumberCounter;

    virtual void GenerageBullet() = 0;
};

class DevilsSnareSkill2 : public DevilsSnareSkill {
public:
    DevilsSnareSkill2(Point* position);

private:
    void GenerageBullet() override;
};
