#pragma once
#include "../ui/CoinText.h"
#include "../ui/StageText.h"
#include "../ui/PlayerState.h"

class UIManager {
public:
    UIManager();
    void Start();
    void Show();
private:
    PlayerState playerState;
    StageText stageText;
    CoinText coinText;
};
