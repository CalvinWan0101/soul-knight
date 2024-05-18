#pragma once
#include "../../Stage.h"

class Stage_3_3 : public Stage {
public:
    Stage_3_3();

protected:
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGate() override;
    void GenerateObstacle() override;
};
