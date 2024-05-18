#pragma once
#include "../../Stage.h"

class Stage_3_1 : public Stage {
public:
    Stage_3_1();

protected:
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGate() override;
    void GenerateObstacle() override;
};
