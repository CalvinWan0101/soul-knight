#pragma once
#include "../../Stage.h"

class Stage_3_6 : public Stage {
public:
    Stage_3_6();

protected:
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGate() override;
    void GenerateObstacle() override;
};
