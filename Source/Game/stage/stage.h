#pragma once
#include "../../Library/gameutil.h"
#include "../utils/point.h"

class Stage {
public:
    Stage();
    virtual ~Stage();
    game_framework::CMovingBitmap* GetBackground();
    void Initialize();
    void Show(Point screenPositoin);
    void AddWall(Point point1, Point point2);
protected:
    int room;
    game_framework::CMovingBitmap background;
    Vec centerOffect;
    virtual void SetMap(int level, int stage);
    virtual void GenerateWall() = 0;
    virtual void SetPlayerPosition() = 0;
    virtual void SetTransferGate() = 0;
    virtual void GenerateObstacle() = 0;
};
