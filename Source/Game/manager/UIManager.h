#pragma once
#include "../ui/StageText.h"
#include "../ui/PlayerState.h"

class UIManager {
public:
    UIManager();
    void Show();
private:
    PlayerState playerState;
    StageText stageText;
};
