#pragma once
#include "EliteSkeleton.h"

class EliteSkeletonShotgun : public EliteSkeleton {
public:
    EliteSkeletonShotgun(double level);
    void Start() override;
    void InitializeWeapon() override;
};
