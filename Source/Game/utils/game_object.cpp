#include "stdafx.h"
#include "game_object.h"

namespace game_framework
{
    GameObject::GameObject() : hitBox(point)
    {
        index = 0;
        factor = 1;
    }

    GameObject::~GameObject()
    {
        for (auto gameObject : fontGameObjects)
        {
            delete gameObject;
        }
        for (auto gameObject : backGameObjects)
        {
            delete gameObject;
        }
    }

    void GameObject::DefaultStart()
    {
        this->Start();
        this->SetCenter();
    }


    void GameObject::DefaultUpdate()
    {
        this->point = this->point + this->speed;
        for (auto gameObject : backGameObjects)
        {
            gameObject->DefaultUpdate();
        }
        for (auto gameObject : fontGameObjects)
        {
            gameObject->DefaultUpdate();
        }
        this->Update();
    }

    void GameObject::Show(Point screenPositoin)
    {
        double screenX = this->point.GetX() - screenPositoin.GetX();
        double screenY = this->point.GetY() - screenPositoin.GetY();
        for (auto gameObject : backGameObjects)
        {
            gameObject->Show(Point(-screenX, -screenY));
        }
        cMovingBitmaps[index].SetTopLeft(static_cast<int>(screenX - centerOffset.GetX()),
                                         static_cast<int>(screenY - centerOffset.GetY()));
        cMovingBitmaps[index].ShowBitmap(factor);
        for (auto gameObject : fontGameObjects)
        {
            gameObject->Show(Point(-screenX, -screenY));
        }
    }

    void GameObject::AddAnimation(vector<string> filepaths, COLORREF color, int delay, bool once)
    {
        CMovingBitmap cMovingBitmap = CMovingBitmap();
        cMovingBitmap.LoadBitmapByString(filepaths, color);
        cMovingBitmap.SetAnimation(delay, once);
        cMovingBitmaps.emplace_back(cMovingBitmap);
    }

    void GameObject::AddFontChild(GameObject* gameObject)
    {
        gameObject->DefaultStart();
        fontGameObjects.emplace_back(gameObject);
    }

    void GameObject::AddBackChild(GameObject* gameObject)
    {
        gameObject->DefaultStart();
        backGameObjects.emplace_back(gameObject);
    }

    Point& GameObject::GetPoint()
    {
        return point;
    }

    Vec& GameObject::GetSpeed()
    {
        return speed;
    }

    void GameObject::SetSpeed(Vec speed)
    {
        this->speed = speed;
    }

    void GameObject::SetCenter()
    {
        if (!this->cMovingBitmaps.empty())
        {
            this->centerOffset.SetVec((double)this->cMovingBitmaps[0].GetWidth() * (factor / 2),
                                      (double)this->cMovingBitmaps[0].GetHeight() * (factor / 2));
        }
    }
}
