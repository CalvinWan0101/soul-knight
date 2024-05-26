#pragma once
#include "Skeleton.h"

class SkeletonShotgun : public Skeleton {
public:
    SkeletonShotgun(double level);
    void Start() override;
    void InitializeWeapon() override;
};
