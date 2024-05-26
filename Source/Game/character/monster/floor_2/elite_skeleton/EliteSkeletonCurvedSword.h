#pragma once
#include "EliteSkeleton.h"

class EliteSkeletonCurvedSword : public EliteSkeleton {
public:
    EliteSkeletonCurvedSword(double level);
    void Start() override;
    void InitializeWeapon() override;
};
