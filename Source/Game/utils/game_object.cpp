#include "stdafx.h"
#include "game_object.h"

#include <algorithm>

namespace game_framework {
    GameObject::GameObject() : hitBox(point) {
        index = 0;
        factor = 1;
    }

    GameObject::~GameObject() {
        for (auto gameObject : frontGameObjects) {
            delete gameObject;
        }
        for (auto gameObject : backGameObjects) {
            delete gameObject;
        }
    }

    void GameObject::DefaultStart() {
        this->Start();
        this->SetCenter();
    }


    void GameObject::DefaultUpdate() {
        this->point = this->point + this->speed;
        for (auto gameObject : backGameObjects) {
            gameObject->DefaultUpdate();
        }
        for (auto gameObject : frontGameObjects) {
            gameObject->DefaultUpdate();
        }
        this->Update();
    }

    void GameObject::Show(Point screenPositoin) {
        double screenX = this->point.GetX() - screenPositoin.GetX();
        double screenY = this->point.GetY() - screenPositoin.GetY();
        for (auto gameObject : backGameObjects) {
            gameObject->Show(Point(-screenX, -screenY));
        }
        cMovingBitmaps[index].SetTopLeft(static_cast<int>(screenX - centerOffset.GetX()),
                                         static_cast<int>(screenY - centerOffset.GetY()));
        cMovingBitmaps[index].ShowBitmap(factor);
        for (auto gameObject : frontGameObjects) {
            gameObject->Show(Point(-screenX, -screenY));
        }
    }

    void GameObject::AddAnimation(vector<string> filepaths, COLORREF color, int delay, bool once) {
        CMovingBitmap cMovingBitmap = CMovingBitmap();
        cMovingBitmap.LoadBitmapByString(filepaths, color);
        cMovingBitmap.SetAnimation(delay, once);
        cMovingBitmaps.emplace_back(cMovingBitmap);
    }

    void GameObject::AddFrontChild(GameObject* gameObject) {
        gameObject->DefaultStart();
        frontGameObjects.emplace_back(gameObject);
    }

    void GameObject::AddBackChild(GameObject* gameObject) {
        gameObject->DefaultStart();
        backGameObjects.emplace_back(gameObject);
    }

    void GameObject::RemoveFrontChile(GameObject* frontChild) {
        size_t frontObjects = frontGameObjects.size();
        frontGameObjects.erase(std::remove_if(frontGameObjects.begin(), frontGameObjects.end(), [frontChild](const GameObject* obj) {
            return frontChild == obj;
        }), frontGameObjects.end());
        if (frontObjects <= frontGameObjects.size()) {
            throw exception("GameObject Not Found.");
        }
    }

    void GameObject::RemoveBackChild(GameObject* backChild) {
        size_t backObjects = backGameObjects.size();
        backGameObjects.erase(std::remove_if(backGameObjects.begin(), backGameObjects.end(), [backChild](const GameObject* obj) {
            return backChild == obj;
        }), backGameObjects.end());
        if (backObjects <= backGameObjects.size()) {
            throw exception("GameObject Not Found.");
        }
    }

    Point& GameObject::GetPoint() {
        return point;
    }

    Vec GameObject::GetSpeed() {
        return speed;
    }

    void GameObject::SetSpeed(Vec direction, double value) {
        direction.SetLength(value);
        this->speed = direction;
    }

    void GameObject::SetSpeed(Vec speed) {
        this->speed = speed;
    }

    void GameObject::SetSpeed(double value) {
        this->speed.SetLength(value);
    }

    void GameObject::SetSpeedX(double x) {
        this->speed.SetX(x);
    }

    void GameObject::SetSpeedY(double y) {
        this->speed.SetY(y);
    }

    void GameObject::SetCenter() {
        if (!this->cMovingBitmaps.empty()) {
            this->centerOffset.SetVec((double)this->cMovingBitmaps[0].GetWidth() * (factor / 2),
                                      (double)this->cMovingBitmaps[0].GetHeight() * (factor / 2));
        }
    }

    void GameObject::AddTag(Tag tag) {
        tags[static_cast<int>(tag)] = true;
    }

    void GameObject::RemoveTag(Tag tag) {
        tags[static_cast<int>(tag)] = false;
    }

    bool GameObject::HasTag(Tag tag) {
        return tags[static_cast<int>(tag)];
    }
    
}
