#pragma once
#include "../../../../../manager/ObjectManager.h"
#include "../../../../../pool/ProjectilePool.h"
#include "../../../../../utils/Point.h"

class DevilsSnareSkill2 {
public:
    DevilsSnareSkill2(Point* position);
    void Update();
    void Activate();

private:
    ObjectManager* objectManager = ObjectManager::Instance();
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    Point* position;
    int bulletCoolDown;
    int bulletNumber;

    void GenerageBullet();
};
