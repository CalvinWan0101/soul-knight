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
    void UpdateGameMap(int level, int stage);\
    Player* GetPlayer();
    TransferGate* GetTransferGate();
    void AddObject(GameObject* object);
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
    GameMap* gameMap = new GameMap();
    Stage* stage;
    TransferGate* transferGate = new TransferGate();
    vector<GameObject*> objects;

    void DeleteObsoleteElements();
    void CollisionDetection();
};
