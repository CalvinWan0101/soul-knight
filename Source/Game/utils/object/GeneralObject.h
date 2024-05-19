#pragma once
#include <bitset>
#include <vector>

#include "GameObject.h"
#include "../Tag.h"
#include "../../utils/Point.h"
#include "../../../Library/gameutil.h"
#include "../../utils/HitBox.h"

using std::vector;

class GeneralObject : public  GameObject{
public:
    GeneralObject();
    ~GeneralObject() override;
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void OnRemove() override;

    void SetHitBoxByRatio(double heightRatio, double widthRatio) override;

    void AddAnimation(vector<string> filepaths, COLORREF color, int delay, bool once);
    void AddFrontChild(GameObject* gameObject);
    void AddBackChild(GameObject* gameObject);
    void RemoveFrontChile(GameObject* frontChild);
    void RemoveBackChild(GameObject* backChild);
    // TODO: Fixed the bug of revised the value by reference directly

protected:
    vector<game_framework::CMovingBitmap> cMovingBitmaps;
    int index;
    vector<GameObject*> frontGameObjects;
    vector<GameObject*> backGameObjects;
    void SetCenter() override;
    
};
