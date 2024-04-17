#pragma once
#include "../../Library/gameutil.h"
#include "../utils/point.h"

class Monster;
class Wall;

class Stage {
public:
    Stage();
    virtual ~Stage();
    game_framework::CMovingBitmap* GetBackground();
    void Initialize();
    void Show(Point screenPositoin);
    void AddWall(Point point1, Point point2);
    virtual void DetectRoom1() = 0;
    virtual void DetectRoom2() = 0;
    virtual void DetectRoom1Cleared() = 0;
    virtual void DetectRoom2Cleared() = 0;
protected:
    bool isInRoom1 = false;
    bool isInRoom2 = false;
    bool room1Cleared = false;
    bool room2Cleared = false;
    std::vector<Wall *> doors;
    std::vector<Monster*> monsters;
    game_framework::CMovingBitmap background;
    Vec centerOffect;
    virtual void SetMap(int level, int stage);
    virtual void GenerateWall() = 0;
    virtual void SetPlayerPosition() = 0;
    virtual void SetTransferGate() = 0;
    virtual void GenerateObstacle() = 0;
    
    virtual void SetRoom1() = 0;
    virtual void SetRoom2() = 0;
};
