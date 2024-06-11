#pragma once
#include <vector>

#include "../character/player/PlayerType.h"
#include "../utils/object/GeneralObject.h"
#include "../projectile/Bullet.h"
#include "../utils/Wallet.h"

using std::vector;

class Monster;
class Player;

class ObjectManager {
public:
    static ObjectManager* Instance();
    ObjectManager();
    ~ObjectManager();
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
    void MakeMoney(int money);
    bool SpendMoney(int money);
    int GetMoney();

    PlayerType GetPlayerType();
    void SetPlayerType(PlayerType playerType);

private:
    int screenX = 0;
    int screenY = 0;
    bool LButtonPressed;
    bool isDisplayHitBox;
    static ObjectManager* instance;
    Player* player;
    vector<GameObject*> objects;
    vector<GameObject*> newObjects;
    Wallet wallet;
    PlayerType playerType;

    void DeleteObsoleteElements();
    void PushNewObjectsToList();
    void CollisionDetection();
};
