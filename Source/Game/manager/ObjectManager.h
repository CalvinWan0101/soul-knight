#pragma once
#include <vector>

#include "../utils/object/GeneralObject.h"
#include "../stage/TransferGate.h"
#include "../projectile/Bullet.h"
#include "../stage/Stage.h"
#include "../stage/stage_implementation/Stage_1_1.h"

using std::vector;

class Monster;
class Player;

class ObjectManager {
public:
    static ObjectManager* Instance();
    ObjectManager();
    ~ObjectManager();
    void SetPlayer(Player* player);
    Player* GetPlayer();
    Point* GetScreenPoint();
    void AddObject(GameObject* object);
    void Start();
    void Update();
    void Show();
    void KeyDown(char key);
    void KeyUp(char key);
    void SetLButtonPress(bool isPressed);
    void SetPlayerVision(Vec vision);
    void SetPlayerPosition(Point playerPosition);

private:
    int screenX = 0;
    int screenY = 0;
    bool LButtonPressed;
    static ObjectManager* instance;
    Player* player;
    vector<GameObject*> objects;
    vector<GameObject*> newObjects;

    void DeleteObsoleteElements();
    void PushNewObjectsToList();
    void CollisionDetection();
};
