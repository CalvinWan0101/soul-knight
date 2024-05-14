#pragma once
#include "../../utils/object/GeneralObject.h"

class Door : public GeneralObject {
public:
    void Start() override;
    void Update() override;
    void LoadResources() override = 0;
    virtual void SetTopLeft(Point leftTop) = 0;
};
