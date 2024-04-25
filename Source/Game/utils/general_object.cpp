#include "stdafx.h"
#include "general_object.h"

#include <algorithm>

namespace game_framework {
    GeneralObject::GeneralObject() : hitBox(position) {
        index = 0;
        factor = 1;
    }

    GeneralObject::~GeneralObject() {
        for (auto generalObject : frontGeneralObjects) {
            delete generalObject;
        }
        for (auto generalObject : backGeneralObjects) {
            delete generalObject;
        }
    }
    
    void GeneralObject::Start() {
        SetCenter();
    }

    void GeneralObject::Update() {
        this->position = this->position + this->speed;
        for (auto generalObject : backGeneralObjects) {
            generalObject->Update();
        }
        for (auto generalObject : frontGeneralObjects) {
            generalObject->Update();
        }
    }

    void GeneralObject::Show(Point screenPositoin) {
        double screenX = this->position.GetX() - screenPositoin.GetX();
        double screenY = this->position.GetY() - screenPositoin.GetY();
        for (auto generalObject : backGeneralObjects) {
            generalObject->Show(screenPositoin);
        }
        cMovingBitmaps[index].SetTopLeft(static_cast<int>(screenX - centerOffset.GetX()),
                                         static_cast<int>(screenY - centerOffset.GetY()));
        cMovingBitmaps[index].ShowBitmap(factor);
        for (auto generalObject : frontGeneralObjects) {
            generalObject->Show(screenPositoin);
        }
    }

    void GeneralObject::AddAnimation(vector<string> filepaths, COLORREF color, int delay, bool once) {
        CMovingBitmap cMovingBitmap = CMovingBitmap();
        cMovingBitmap.LoadBitmapByString(filepaths, color);
        cMovingBitmap.SetAnimation(delay, once);
        cMovingBitmaps.emplace_back(cMovingBitmap);
    }

    void GeneralObject::AddFrontChild(GeneralObject* generalObject) {
        generalObject->Start();
        frontGeneralObjects.emplace_back(generalObject);
    }

    void GeneralObject::AddBackChild(GeneralObject* generalObject) {
        generalObject->Start();
        backGeneralObjects.emplace_back(generalObject);
    }

    void GeneralObject::RemoveFrontChile(GeneralObject* frontChild) {
        size_t frontObjects = frontGeneralObjects.size();
        frontGeneralObjects.erase(std::remove_if(frontGeneralObjects.begin(), frontGeneralObjects.end(), [frontChild](const GeneralObject* obj) {
            return frontChild == obj;
        }), frontGeneralObjects.end());
        if (frontObjects <= frontGeneralObjects.size()) {
            throw exception("GeneralObject Not Found.");
        }
    }

    void GeneralObject::RemoveBackChild(GeneralObject* backChild) {
        size_t backObjects = backGeneralObjects.size();
        backGeneralObjects.erase(std::remove_if(backGeneralObjects.begin(), backGeneralObjects.end(), [backChild](const GeneralObject* obj) {
            return backChild == obj;
        }), backGeneralObjects.end());
        if (backObjects <= backGeneralObjects.size()) {
            throw exception("GeneralObject Not Found.");
        }
    }

    Point GeneralObject::GetPosition() {
        return position;
    }

    void GeneralObject::SetPosition(double x, double y) {
        this->position.SetPoint(x, y);
    }

    void GeneralObject::SetPosition(Point point) {
        this->position.SetPoint(point.GetX(), point.GetY());
    }

    void GeneralObject::SetX(double x) {
        this->position.SetX(x);
    }

    void GeneralObject::SetY(double y) {
        this->position.SetY(y);
    }

    Vec GeneralObject::GetSpeed() {
        return speed;
    }

    void GeneralObject::SetSpeed(Vec direction, double value) {
        direction.SetLength(value);
        this->speed = direction;
    }

    void GeneralObject::SetSpeed(Vec speed) {
        this->speed = speed;
    }

    void GeneralObject::SetSpeed(double value) {
        this->speed.SetLength(value);
    }

    void GeneralObject::SetSpeedX(double x) {
        this->speed.SetX(x);
    }

    void GeneralObject::SetSpeedY(double y) {
        this->speed.SetY(y);
    }

    void GeneralObject::SetCenter() {
        if (!this->cMovingBitmaps.empty()) {
            this->centerOffset.SetVec(static_cast<double>(cMovingBitmaps[0].GetWidth()) * (factor / 2.0),
                                      static_cast<double>(cMovingBitmaps[0].GetHeight()) * (factor / 2.0));
        }
    }

    void GeneralObject::AddTag(Tag tag) {
        tags[static_cast<int>(tag)] = true;
    }

    void GeneralObject::RemoveTag(Tag tag) {
        tags[static_cast<int>(tag)] = false;
    }

    bool GeneralObject::HasTag(Tag tag) {
        return tags[static_cast<int>(tag)];
    }

    void GeneralObject::SetHitBox(double height, double width) {
        hitBox.SetHeight(height);
        hitBox.SetWidth(width);
    }

    void GeneralObject::SetHitBoxByRatio(double heightRatio, double widthRatio) {
        hitBox.SetHeight(static_cast<double>(cMovingBitmaps[0].GetHeight()) * heightRatio);
        hitBox.SetWidth(static_cast<double>(cMovingBitmaps[0].GetWidth()) * widthRatio);
    }

    HitBox& GeneralObject::GetHitBox() {
        return hitBox;
    }

    void GeneralObject::Collision(GeneralObject* generalObject) {
        // TODO: Override by derived class.
    }

}
