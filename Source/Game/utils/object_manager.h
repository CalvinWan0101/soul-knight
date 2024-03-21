#pragma once
#include <vector>

#include "game_object.h"

class Monster;
class Player;

class ObjectManager
{
public:
    static ObjectManager *Instance();
    ObjectManager();
    ~ObjectManager();
    void SetPlayer(Player* player);
    void AddMonster(Monster* monster);
    void Start();
    void Update();
    void Show();
    void KeyDown(char key);
    void KeyUp(char key);
    void SetPlayerVision(Vec vision);

private:
    int screenX = 0;
    int screenY = 0;
    static ObjectManager* instance;
    Player* player;
    std::vector<Monster*> monsters;
    std::vector<game_framework::GameObject*> objects;
    // TODO: Process the collision of different objects
    // std::vector<game_framework::GameObject*> objectsToDelete;
};
