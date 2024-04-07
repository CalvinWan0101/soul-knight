#pragma once

class StageManager {
public:
    static StageManager* Instance();
    StageManager();
    ~StageManager();
    int GetLevel();
    int GetStage();
    void NextStage();
private:
    static StageManager* instance;
    int level;
    int stage;

    void UpdatePlayerPosition();
};
