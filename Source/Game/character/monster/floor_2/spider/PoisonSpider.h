#pragma once
#include "BaseSpider.h"

class PoisonSpider : public BaseSpider {
public:
    PoisonSpider(double level);
    void Start() override;
    void LoadResources() override;
    void OnDead() override;
};
