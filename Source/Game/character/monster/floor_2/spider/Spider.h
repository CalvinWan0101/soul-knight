#pragma once
#include "BaseSpider.h"

class Spider : public BaseSpider{
public:
    Spider(double level);
    void Start() override;
    void LoadResources() override;
    void OnDead() override;
};
