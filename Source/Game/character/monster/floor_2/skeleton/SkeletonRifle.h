#pragma once
#include "Skeleton.h"

class SkeletonRifle : public Skeleton {
public:
    SkeletonRifle(double level);
    void Start() override;
    void InitializeWeapon() override;
};
