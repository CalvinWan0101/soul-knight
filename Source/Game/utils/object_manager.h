#pragma once
#include <vector>

#include "game_map.h"
#include "game_object.h"
#include "transfer_gate.h"
#include "../bullet/bullet.h"
#include "../stage/stage.h"
#include "../stage/stage_1_1.h"

using game_framework::GameObject;
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

    void DeleteObsoleteElements();
    void CollisionDetection();
};
