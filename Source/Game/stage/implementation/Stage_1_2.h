#pragma once
#include "../Stage.h"

class Stage_1_2 : public Stage {
public:
    Stage_1_2();

protected:
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGate() override;
    void GenerateObstacle() override;
};
