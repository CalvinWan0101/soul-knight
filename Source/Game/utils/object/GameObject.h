#pragma once
#include <bitset>
#include <vector>

#include "../../../Library/gameutil.h"
#include "../HitBox.h"
#include "../Point.h"
#include "../Tag.h"

enum class Tag;

class GameObject {
public:
    GameObject();
    virtual ~GameObject();
    virtual void Start();
    virtual void Update();
    virtual void LoadResources() = 0;
    virtual void Show(Point screenPositoin) = 0;

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
    void SetVisible(bool visiable);
    void AddTag(Tag tag);
    void RemoveTag(Tag tag);
    bool HasTag(Tag tag);
    void SetHitBox(double height, double width);
    virtual void SetHitBoxByRatio(double heightRatio, double widthRatio) = 0;
    HitBox& GetHitBox();
    virtual void Collision(GameObject* gameObject);

protected:
    Point position;
    Vec centerOffset;
    HitBox hitBox;
    Vec speed;
    Vec showOffset;
    bool visible;
    virtual void SetCenter() = 0;

private:
    bool resourcesIsLoaded;
    bitset<static_cast<int>(Tag::Count)> tags;
};
