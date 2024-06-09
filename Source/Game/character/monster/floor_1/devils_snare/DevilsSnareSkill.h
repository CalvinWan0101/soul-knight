#pragma once
#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"

class DevilsSnareSkill {
public:
    DevilsSnareSkill(Point* position, int bulletCoolDown, int bulletNumber);
    virtual void Update();
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

class DevilsSnareSkill1 : public DevilsSnareSkill {
public:
    DevilsSnareSkill1(Point* position);

private:
    void GenerageBullet() override;
};

class DevilsSnareSkill2 : public DevilsSnareSkill {
public:
    DevilsSnareSkill2(Point* position);
    void Update() override;

private:
    Vec rotation = Vec(1.0, 1.0);
    void GenerageBullet() override;
};

class DevilsSnareSkill3 : public DevilsSnareSkill {
public:
    DevilsSnareSkill3(Point* position);

private:
    void GenerageBullet() override;
};
