#pragma once
#include <vector>

#include "../Utils/point.h"
#include "../../Library/gameutil.h"

namespace game_framework
{
    class GameObject
    {
    public:
        GameObject();
        virtual ~GameObject();
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void Show(Point screenPositoin);
        Point GetPoint();
        Vec GetSpeed();

    protected:
        Point point;
        Vec speed;
        std::vector<CMovingBitmap> cMovingBitmaps;
        int index;
    };
}