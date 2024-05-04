#pragma once
#include "Room.h"
#include "../../Library/gameutil.h"
#include "../utils/Point.h"

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
    void IsInsideRoom();
    void IsRoomCleared();

protected:
    game_framework::CMovingBitmap background;
    Vec centerOffset;
    virtual void SetMap(int level, int stage);
    virtual void GenerateWall() = 0;
    virtual void SetPlayerPosition() = 0;
    virtual void SetTransferGate() = 0;
    virtual void GenerateObstacle() = 0;
    std::vector<Room*> rooms;
};
