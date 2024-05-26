#pragma once
#include "EliteSkeleton.h"

class EliteSkeletonRifle : public EliteSkeleton {
public:
    EliteSkeletonRifle(double level);
    void Start() override;
    void InitializeWeapon() override;
};
