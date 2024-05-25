#pragma once
#include "Skeleton.h"

class SkeletonCurvedSword : public Skeleton {
public:
    SkeletonCurvedSword(double level);
    void Start() override;
    void InitializeWeapon() override;
};
