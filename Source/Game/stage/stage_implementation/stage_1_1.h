#pragma once
#include "../stage.h"

class Stage_1_1 : public Stage {
public:
    Stage_1_1();
    ~Stage_1_1() override;
    void DetectRoom1() override;
    void DetectRoom2() override;
    void DetectRoom1Cleared() override;
    void DetectRoom2Cleared() override;
protected:
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGate() override;
    void GenerateObstacle() override;
    void SetRoom1() override;
    void SetRoom2() override;
};
