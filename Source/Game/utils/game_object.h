#pragma once
#include <vector>

#include "tag.h"
#include "../utils/point.h"
#include "../../Library/gameutil.h"
#include "../utils/hit_box.h"

using std::vector;

namespace game_framework {
    class GameObject {
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
        void RemoveFrontChile(GameObject* frontChild);
        void RemoveBackChild(GameObject* backChild);
        // TODO: Fixed the bug of revised the value by reference directly
        Point& GetPoint();
        Vec GetSpeed();
        void SetSpeed(Vec direction, double value);
        void SetSpeed(Vec speed);
        void SetSpeed(double value);
        void SetSpeedX(double x);
        void SetSpeedY(double y);

    protected:
        Point point;
        Vec centerOffset;
        HitBox hitBox;
        Vec speed;
        vector<Tag::Type> tag;
        vector<CMovingBitmap> cMovingBitmaps;
        int index;
        vector<GameObject*> frontGameObjects;
        vector<GameObject*> backGameObjects;
        virtual void SetCenter();

    private:
        double factor;
    };
}
