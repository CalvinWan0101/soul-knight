#pragma once
#include <vector>

#include "../utils/point.h"
#include "../../Library/gameutil.h"
#include "../utils/hit_box.h"

namespace game_framework
{
    class GameObject
    {
    public:
        GameObject();
        virtual ~GameObject();
        void DefaultStart();
        virtual void Start() = 0;
        void DefaultUpdate();
        virtual void Update() = 0;
        virtual void Show(Point screenPositoin);

        void AddAnimation(vector<string> filepaths, COLORREF color, int delay, bool once);
        void AddFrontChild(GameObject* gameObject);
        void AddBackChild(GameObject* gameObject);
        Point& GetPoint();
        Vec& GetSpeed();
        void SetSpeed(Vec speed);

    protected:
        Point point;
        Vec centerOffset;
        HitBox hitBox;
        Vec speed;
        std::vector<CMovingBitmap> cMovingBitmaps;
        int index;
        std::vector<GameObject*> frontGameObjects;
        std::vector<GameObject*> backGameObjects;
        virtual void SetCenter();

    private:
        double factor;
    };
}
