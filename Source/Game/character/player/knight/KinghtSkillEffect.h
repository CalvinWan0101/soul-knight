#pragma once
#include "../../../utils/object/GeneralObject.h"

class KinghtSkillEffect : public GeneralObject{
public:
    KinghtSkillEffect(Point* authorPoint);
    void Update() override;
    void LoadResources() override;

private:
    Point* authorPoint;
};
