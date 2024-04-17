#pragma once

class Stage;

class StageManager {
public:
    static StageManager* Instance();
    StageManager();
    ~StageManager();
    void Update();
    Stage* GetStage();
    void Initiliaze();
    void NextStage();
    bool InRoom();

private:
    static StageManager* instance;
    int level;
    int stage;
    bool inRoom;
    Stage* gameStage;
};
