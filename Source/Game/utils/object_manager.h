#pragma once
#include <vector>

#include "game_object.h"
#include "../bullet/bullet.h"

using game_framework::GameObject;

class Monster;
class Player;

class ObjectManager {
public:
    static ObjectManager* Instance();
    ObjectManager();
    ~ObjectManager();
    void SetPlayer(Player* player);
    void AddMonster(Monster* monster);
    void AddObject(GameObject* object);
    void RemoveObject(GameObject* object);
    void Start();
    void Update();
    void Show();
    void KeyDown(char key);
    void KeyUp(char key);
    void SetLButtonPress(bool isPressed);
    void SetPlayerVision(Vec vision);

private:
    int screenX = 0;
    int screenY = 0;
    bool LButtonPressed;
    static ObjectManager* instance;
    Player* player;
    std::vector<game_framework::GameObject*> objects;
    std::vector<game_framework::GameObject*> objectsToDelete;
};
