#pragma once
#include "../../Stage.h"

class Stage_3_4 : public Stage {
public:
    Stage_3_4();

protected:
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGate() override;
    void GenerateObstacle() override;
};
