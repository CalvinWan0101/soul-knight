#pragma once
#include "../../Stage.h"

class Stage_1_1 : public Stage {
public:
    Stage_1_1();

protected:
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGate() override;
    void GenerateObstacle() override;
};
