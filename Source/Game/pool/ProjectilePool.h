#pragma once
#include "../projectile/InvisibleShockWave.h"
#include "../projectile/bullet/Arrow.h"
#include "../projectile/bullet/BadPistolBullet.h"
#include "../projectile/shock_wave/HammerWave.h"

class ProjectilePool {
public:
    static ProjectilePool* Instance();
    ProjectilePool();
    ~ProjectilePool();

    // bullet
    Arrow* AcquireArrow();
    void ReleaseArrow(Arrow* arrow);
    
    BadPistolBullet* AcquireBadPistolBullet();
    void ReleaseBadPistolBullet(BadPistolBullet* bullet);

    // shock wave
    HammerWave* AcquireHammerWave();
    void ReleaseHammerWave(HammerWave* hammerWave);

    // other
    InvisibleShockWave* AcquireInvisibleShockWave();
    void ReleaseInvisibleShockWave(InvisibleShockWave* invisibleShockWave);
    
private:
    static ProjectilePool* instance;
    // bullet
    std::vector<Arrow*> arrows;
    std::vector<BadPistolBullet*> badPistolBullets;

    // shock wave
    std::vector<HammerWave*> hammerWaves;

    // other
    std::vector<InvisibleShockWave*> invisibleShockWaves;
};
