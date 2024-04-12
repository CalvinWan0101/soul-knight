#pragma once
#include "stage.h"

class Stage_1_1 : public Stage {
public:
    Stage_1_1();
    ~Stage_1_1() override;
protected:
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGatePosition() override;
    void GenerateObstacle() override;
};
