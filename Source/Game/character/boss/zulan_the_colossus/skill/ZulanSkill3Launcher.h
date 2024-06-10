#pragma once
#include "../../../../utils/object/InvisibleObject.h"

class ZulanSkill3Launcher : public InvisibleObject
{
public:
    ZulanSkill3Launcher(Point point);
    void Update() override;
private:
    int aliveFrame;
    Vec launchAngle;
    int splitIntervalCounter;
};
