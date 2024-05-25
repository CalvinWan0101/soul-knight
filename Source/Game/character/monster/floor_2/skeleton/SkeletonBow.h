#pragma once
#include "Skeleton.h"

class SkeletonBow : public Skeleton {
public:
    SkeletonBow(double level);
    void Start() override;
    void InitializeWeapon() override;
};
