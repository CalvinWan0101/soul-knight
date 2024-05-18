#pragma once
#include "../../Stage.h"

class Stage_2_5 : public Stage {
public:
    Stage_2_5();

protected:
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGate() override;
    void GenerateObstacle() override;
};
