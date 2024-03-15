#pragma once
#include <vector>

#include "../Utils/point.h"
#include "../../Library/gameutil.h"
#include "../Utils/hit_box.h"

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
        void AddFontChild(GameObject* gameObject);
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
        std::vector<GameObject*> fontGameObjects;
        std::vector<GameObject*> backGameObjects;
        virtual void SetCenter();

    private:
        double factor;
    };
}
