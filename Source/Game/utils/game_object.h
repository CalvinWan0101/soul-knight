#pragma once
#include <bitset>
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
        virtual void Start();
        virtual void Update();
        virtual void Show(Point screenPositoin);

        void AddAnimation(vector<string> filepaths, COLORREF color, int delay, bool once);
        void AddFrontChild(GameObject* gameObject);
        void AddBackChild(GameObject* gameObject);
        void RemoveFrontChile(GameObject* frontChild);
        void RemoveBackChild(GameObject* backChild);
        // TODO: Fixed the bug of revised the value by reference directly
        Point GetPosition();
        void SetPosition(double x, double y);
        void SetPosition(Point point);
        void SetX(double x);
        void SetY(double y);
        Vec GetSpeed();
        void SetSpeed(Vec direction, double value);
        void SetSpeed(Vec speed);
        void SetSpeed(double value);
        void SetSpeedX(double x);
        void SetSpeedY(double y);
        void AddTag(Tag tag);
        void RemoveTag(Tag tag);
        bool HasTag(Tag tag);
        void SetHitBox(double height, double width);
        void SetHitBoxByRatio(double heightRatio, double widthRatio);
        HitBox& GetHitBox();
        virtual void Collision(GameObject* gameObject);

    protected:
        Point position;
        Vec centerOffset;
        HitBox hitBox;
        Vec speed;
        bitset<static_cast<int>(Tag::Count)> tags;
        vector<CMovingBitmap> cMovingBitmaps;
        int index;
        vector<GameObject*> frontGameObjects;
        vector<GameObject*> backGameObjects;
        virtual void SetCenter();

    private:
        double factor;
    };
}
