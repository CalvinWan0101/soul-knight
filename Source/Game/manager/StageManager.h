#pragma once
#include "../stage/TransferGate.h"

class Stage;

class StageManager {
public:
    static StageManager* Instance();
    StageManager();
    ~StageManager();
    void Update();
    Stage* GetStage();
    int GetStageNumber();
    int GetLevelNumber();
    void Initiliaze();
    void NextStage();
    void SetTransferGatePosition(Point position);
    bool GetSuccess();

private:
    static StageManager* instance;
    int level;
    int stage;
    Stage* gameStage = nullptr;
    TransferGate* transferGate = nullptr;
    bool success;
};
